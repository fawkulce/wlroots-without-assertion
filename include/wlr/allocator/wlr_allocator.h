#ifndef WLR_ALLOCATOR_H
#define WLR_ALLOCATOR_H

#include <wayland-server-core.h>

struct wlr_allocator_interface;
struct wlr_backend;
struct wlr_drm_format;
struct wlr_renderer;

struct wlr_allocator {
	const struct wlr_allocator_interface *impl;

	// Capabilities of the buffers created with this allocator
	uint32_t buffer_caps;

	struct {
		struct wl_signal destroy;
	} events;
};

/**
 * Creates the adequate wlr_allocator given a backend and a renderer
 */
struct wlr_allocator *wlr_allocator_autocreate(struct wlr_backend *backend,
	struct wlr_renderer *renderer);
/**
 * Destroy the allocator.
 */
void wlr_allocator_destroy(struct wlr_allocator *alloc);

#endif
