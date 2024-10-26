#ifndef _allegro_library_debug_h_
#define _allegro_library_debug_h_

import <cassert>;
import allegro;

#if defined(DEBUGMODE) || defined(ALLEGRO_CFG_RELEASE_LOGGING)
    /* Must not be used with a trailing semicolon. */
#ifdef ALLEGRO_GCC
#define ALLEGRO_DEBUG_CHANNEL(x) \
         static const_cptr_t __al_debug_channel __attribute__((unused)) = x;
#else
#define ALLEGRO_DEBUG_CHANNEL(x) \
         static const_cptr_t __al_debug_channel = x;
#endif
#define ALLEGRO_TRACE_CHANNEL_LEVEL(channel, level)                        \
      !_al_trace_prefix(channel, level, __FILE__, __LINE__, __func__)         \
      ? (void)0 : _al_trace_suffix
#else
#define ALLEGRO_TRACE_CHANNEL_LEVEL(channel, x)  1 ? (void) 0 : _al_trace_suffix
#define ALLEGRO_DEBUG_CHANNEL(x)
#endif

#define ALLEGRO_TRACE_LEVEL(x)   ALLEGRO_TRACE_CHANNEL_LEVEL(__al_debug_channel, x)
#define ALLEGRO_DEBUG            ALLEGRO_TRACE_LEVEL(0)
#define ALLEGRO_INFO             ALLEGRO_TRACE_LEVEL(1)
#define ALLEGRO_WARN             ALLEGRO_TRACE_LEVEL(2)
#define ALLEGRO_ERROR            ALLEGRO_TRACE_LEVEL(3)

#ifdef __clang_analyzer__
    /* Clang doesn't understand _al_user_assert_handler, so we simplify the
     * definition for analysis purposes. */
#define ALLEGRO_ASSERT(e) assert(e)
#else
#ifdef NDEBUG
#define ALLEGRO_ASSERT(e)	((void)(0 && (e)))
#else
#define ALLEGRO_ASSERT(e)                                                  \
         ((e) ? (void) 0                                                         \
         : (al::_user_assert_handler) ?                                           \
            al::_user_assert_handler(#e, __FILE__, __LINE__, __func__)            \
         : assert(e))
#endif
#endif

    /* Compile time assertions. */
#define ALLEGRO_ASSERT_CONCAT_(a, b)   a##b
#define ALLEGRO_ASSERT_CONCAT(a, b)    ALLEGRO_ASSERT_CONCAT_(a, b)
#define ALLEGRO_STATIC_ASSERT(module, e) \
   struct ALLEGRO_ASSERT_CONCAT(static_assert_##module##_line_, __LINE__) \
      { unsigned int32_t bf : !!(e); }

/* We are lazy and use just ASSERT while Allegro itself is compiled. */
#ifdef ALLEGRO_LIB_BUILD
#define ASSERT(x) ALLEGRO_ASSERT(x)
#endif

#endif // !_allegro_library_debug_h_
