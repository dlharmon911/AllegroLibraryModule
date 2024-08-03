#ifndef _allegro_library_memory_h_
#define _allegro_library_memory_h_

import allegro:memory;

#define al_malloc(n)		(al::malloc_with_context((n), __LINE__, __FILE__, __func__))
#define al_free(p)			(al::free_with_context((p), __LINE__, __FILE__, __func__))
#define al_realloc(p, n)	(al::realloc_with_context((p), (n), __LINE__, __FILE__, __func__))
#define al_calloc(c, n)		(al::calloc_with_context((c), (n), __LINE__, __FILE__, __func__))

#endif // !_allegro_library_memory_h_
