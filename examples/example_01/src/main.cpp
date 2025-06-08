import allegro;
import allegro.primitives_addon;
import std;

namespace APP
{
	const char* const TITLE{ "Module Example" };
	constexpr ALLEGRO::VECTOR_2D<int32_t> SCREEN_SIZE{ 800, 600 };
	constexpr ALLEGRO::VECTOR_2D<float> SCREEN_CENTER{ 400.0f, 300.0f };
	constexpr double TIMING{ 60.0 };
	constexpr ALLEGRO::COLOR EIGENGRAU{ 0.0862745098f, 0.0862745098f, 0.0862745098f, 1.0f };
	constexpr ALLEGRO::COLOR CIRCLE_COLOR_INSIDE{ 1.0f, 1.0f, 0.0f, 1.0f };
	constexpr ALLEGRO::COLOR CIRCLE_COLOR_BORDER{ 1.0f, 0.5f, 0.0f, 1.0f };
	constexpr float CIRCLE_RADIUS{ 200.0f };
	constexpr float CIRCLE_THICKNESS{ 15.0f };
}

class app_t
{
public:
	/**
	Runs the program.
	@param argument_array - command line arguments
	@return 0 with no errors, negative on error
	*/
	static int32_t run(const std::vector<std::string>& argument_array);


private:
	/**
	App class constructor
	@param none
	@return none
	*/
	app_t() = default;

	/**
	App class deconstructor
	@param none
	@return none
	*/
	~app_t() = default;
	app_t(const app_t& app) = delete;
	app_t& operator = (const app_t& app) = delete;


	/**
	Initializes application
	@param argument_array - command line arguments
	@return 0 with no errors, negative on error
	*/
	int32_t init(const std::vector<std::string>& argument_array);

	/**
	Shutdown and deinitialze everything
	@param none
	@return none
	*/
	void shutdown();

	/**
	Basic loop of input/logic/draw
	@param none
	@return 0 with no errors, negative on error
	*/
	void loop();

	/**
	Output to the screen
	@param none
	@return none
	*/
	void draw();

	/**
	Process all logic
	@param none
	@return none
	*/
	void logic();

	/**
	Process any incoming events
	@param none
	@return none
	*/
	void input();

	ALLEGRO::DISPLAY m_display{};
	ALLEGRO::EVENT_QUEUE m_event_queue{};
	ALLEGRO::TIMER m_timer{};
	bool m_kill{ false };
	bool m_update{ false };
	bool m_dirty{ true };
};

int32_t main(int32_t argc, char** argv)
{
	std::vector<std::string> argument_array{};

	for (int i = 0; i < argc; ++i)
	{
		argument_array.push_back(argv[i]);
	}

	return app_t::run(argument_array);
}

int32_t app_t::run(const std::vector<std::string>& argument_array)
{
	app_t app{};
	int32_t rv{ 0 };

	if ((rv = app.init(argument_array)) == 0)
	{
		app.loop();
	}

	app.shutdown();

	return rv;
}

int32_t app_t::init(const std::vector<std::string>& argument_array)
{
	if (!al::init())
	{
		return -1;
	}

	if (!al::primitives_addon::is_initialized())
	{
		if (!al::primitives_addon::init())
		{
			return -1;
		}
	}

	if (!al::install_keyboard())
	{
		return -1;
	}

	if (!al::install_mouse())
	{
		return -1;
	}

	al::set_new_window_title(APP::TITLE);
	al::set_new_display_flags(ALLEGRO::DISPLAY_FLAG_RESIZABLE | ALLEGRO::DISPLAY_FLAG_WINDOWED);
	this->m_display = al::create_display(APP::SCREEN_SIZE);
	if (!this->m_display)
	{
		return -1;
	}
	al::clear_to_color(APP::EIGENGRAU);
	al::flip_display();

	this->m_timer = al::create_timer(APP::TIMING);
	if (!this->m_timer)
	{
		return -1;
	}

	m_event_queue = al::create_event_queue();
	if (!m_event_queue)
	{
		return -1;
	}

	al::register_event_source(this->m_event_queue, al::get_display_event_source(this->m_display));
	al::register_event_source(this->m_event_queue, al::get_timer_event_source(this->m_timer));
	al::register_event_source(this->m_event_queue, al::get_keyboard_event_source());
	al::register_event_source(this->m_event_queue, al::get_mouse_event_source());

	const auto now = std::chrono::system_clock::now();
	const std::time_t t_c = std::chrono::system_clock::to_time_t(now);
	std::srand((uint32_t)t_c);

	return 0;
}

void app_t::shutdown()
{
	if (this->m_timer)
	{
		al::stop_timer(this->m_timer);
	}

	this->m_event_queue.reset();
	this->m_timer.reset();
	this->m_display.reset();

	if (al::primitives_addon::is_initialized())
	{
		al::primitives_addon::shutdown();
	}

	if (al::is_system_installed())
	{
		al::uninstall_system();
	}
}

void app_t::loop()
{
	while (!this->m_kill)
	{
		this->input();

		if (this->m_update)
		{
			this->logic();
			this->m_update = false;
			this->m_dirty = true;
		}

		if (this->m_dirty)
		{
			this->draw();
			this->m_dirty = false;
		}
	}
}

void app_t::draw()
{
	al::clear_to_color(APP::EIGENGRAU);

	al::draw_filled_circle(APP::SCREEN_CENTER, APP::CIRCLE_RADIUS, APP::CIRCLE_COLOR_INSIDE);
	al::draw_circle(APP::SCREEN_CENTER, APP::CIRCLE_RADIUS - (APP::CIRCLE_THICKNESS * 0.5f), APP::CIRCLE_COLOR_BORDER, APP::CIRCLE_THICKNESS);

	al::flip_display();
}

void app_t::logic()
{

}

void app_t::input()
{
	ALLEGRO::EVENT event{};

	while (!al::is_event_queue_empty(this->m_event_queue))
	{
		al::get_next_event(this->m_event_queue, event);
		switch (event.type)
		{
		case ALLEGRO::EVENT_TYPE_TIMER:
		{
			this->m_update = true;
		} break;

		case ALLEGRO::EVENT_TYPE_DISPLAY_RESIZE:
		{
			al::acknowledge_resize(this->m_display);
			this->m_dirty = true;
		} break;

		case ALLEGRO::EVENT_TYPE_DISPLAY_CLOSE:
		{
			this->m_kill = true;
		} break;
		default: break;
		}
	}
}

