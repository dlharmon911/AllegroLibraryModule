export module application;

import <ctime>;
import <cstdlib>;
import <string>;
import <vector>;
import <memory>;
import <iostream>;
import <fstream>;
import allegro;
import allegro.image_addon;

export class application
{
public:
	static int32_t run(int32_t argc, char** argv)
	{
		std::vector<std::string> args;
		int32_t rv = 0;
		std::fstream fileOut;
		std::streambuf* streamBuf = nullptr;
		application app;

		fileOut.open("logs\\output.txt", std::ios::out);

		if (fileOut.is_open())
		{
			streamBuf = std::cout.rdbuf();
			std::cout.rdbuf(fileOut.rdbuf());
		}

		for (int32_t i = 0; i < argc; ++i)
		{
			args.push_back(argv[i]);
		}

		if ((rv = app.init(args)) == 0)
		{
			app.loop();
		}

		app.shutdown();

		if (fileOut.is_open())
		{
			std::cout.rdbuf(streamBuf);
			fileOut.close();
		}

		return rv;
	}

private:
	application() : m_display(), m_buffer(), m_queue(), m_timer(), m_kill(false), m_dirty(true), m_counter(0)
	{
	}

	~application()
	{
	}

	int32_t init(const std::vector<std::string>& args)
	{
		std::cout << "Initialization Begin\n";

		std::cout << "Initializing Allegro Library: ";
		if (!al::init())
		{
			std::cout << "failed\n";
			return -1;
		}
		std::cout << "pass\n";

#ifndef _DEBUG
		// set the directory to the path of the exe
		ALLEGRO::PATH base_path = al::get_standard_path(ALLEGRO::RESOURCES_PATH);

		if (base_path)
		{
			al::make_path_canonical(base_path);
			al::change_directory(al::path_cstr(base_path, ALLEGRO::NATIVE_PATH_SEP));
			base_path.reset();
		}
#endif

		std::cout << "Initializing Keyboard: ";
		if (!al::install_keyboard())
		{
			std::cout << "failed\n";
			return -1;
		}
		std::cout << "pass\n";

		std::cout << "Initializing Mouse: ";
		if (!al::install_mouse())
		{
			std::cout << "failed\n";
			return -1;
		}
		std::cout << "pass\n";

		std::cout << "Initializing Image Addon: ";
		if (!al::image_addon::init())
		{
			std::cout << "failed\n";
			return -1;
		}
		std::cout << "pass\n";

		std::cout << "Creating Display: ";
		al::set_new_display_flags(ALLEGRO::DISPLAY_FLAG_WINDOWED | ALLEGRO::DISPLAY_FLAG_RESIZABLE);
		this->m_display = al::create_display(SCREEN_W, SCREEN_H);
		if (!this->m_display)
		{
			std::cout << "failed\n";
			return -1;
		}
		std::cout << "pass\n";

		ALLEGRO::BITMAP icon = al::load_bitmap("data\\images\\icon.png");
		if (icon)
		{
			al::set_display_icon(this->m_display, icon);
			icon.reset();
		}
		al::set_window_title(this->m_display, APPNAME);

		std::cout << "Creating Buffer Bitmap: ";
		this->m_buffer = al::create_bitmap(SCREEN_W, SCREEN_H);
		if (!this->m_buffer)
		{
			std::cout << "failed\n";
			return -1;
		}
		std::cout << "pass\n";

		std::cout << "Creating Event Queue: ";
		this->m_queue = al::create_event_queue();
		if (!this->m_queue)
		{
			std::cout << "failed\n";
			return -1;
		}
		std::cout << "pass\n";

		std::cout << "Creating Logic Timer: ";
		this->m_timer = al::create_timer(1.0 / TIMING);
		if (!this->m_timer)
		{
			std::cout << "failed\n";
			return -1;
		}
		std::cout << "pass\n";

		al::register_event_source(this->m_queue, al::get_display_event_source(this->m_display));
		al::register_event_source(this->m_queue, al::get_timer_event_source(this->m_timer));
		al::register_event_source(this->m_queue, al::get_mouse_event_source());
		al::register_event_source(this->m_queue, al::get_keyboard_event_source());

		srand((uint32_t)(al::get_time() * 1000000.0));

		al::start_timer(this->m_timer);

		std::cout << "Initialization Complete\n" << std::endl;

		return 0;
	}

	void shutdown()
	{
		std::cout << "\nShutdown Begin\n";

		al::stop_timer(this->m_timer);
		this->m_timer.reset();
		std::cout << "Timer Destroyed\n";

		this->m_queue.reset();
		std::cout << "Event Queue Destroyed\n";

		this->m_display.reset();
		std::cout << "Display Destroyed\n";

		std::cout << "Shutdown Complete\n" << std::endl;
	}

	int32_t loop()
	{
		while (!this->m_kill)
		{
			this->input();

			while (this->m_counter > 0)
			{
				this->logic();
				--this->m_counter;
			}

			if (this->m_dirty)
			{
				this->draw();
				this->m_dirty = false;
			}

			al::rest(0.01);
		}

		return 0;
	}

	void draw()
	{
		static float a = 0.0f;

		ALLEGRO::BITMAP target = al::get_target_bitmap();
		al::set_target_bitmap(this->m_buffer);

		al::clear_to_color(al::map_rgb(64, 0, 64));

		al::set_target_bitmap(target);
		al::draw_scaled_bitmap(this->m_buffer,
								{ 0, 0, al::get_bitmap_width(this->m_buffer), al::get_bitmap_height(this->m_buffer) },
								{ 0, 0, al::get_display_width(this->m_display), al::get_display_height(this->m_display) },
								ALLEGRO::BITMAP_FLIP_NONE);
		al::flip_display();
	}

	void logic()
	{
		this->m_dirty = true;
	}

	void input()
	{
		static ALLEGRO::EVENT event;

		while (!al::is_event_queue_empty(this->m_queue))
		{
			al::get_next_event(this->m_queue, event);

			switch (event.type)
			{
			case ALLEGRO::EVENT_TYPE_TIMER:
			{
				++this->m_counter;
			} break;

			case ALLEGRO::EVENT_TYPE_DISPLAY_CLOSE:
			{
				this->m_kill = true;
			} break;
			}
		}
	}

	ALLEGRO::DISPLAY m_display;
	ALLEGRO::BITMAP m_buffer;
	ALLEGRO::EVENT_QUEUE m_queue;
	ALLEGRO::TIMER m_timer;
	bool m_kill;
	bool m_dirty;
	int32_t m_counter;

	const int32_t SCREEN_W = 800;
	const int32_t SCREEN_H = 600;
	const double TIMING = 60.0;
	const char* APPNAME = "Tic Tac Toe";
};

