/* Generated by wayland-scanner 1.20.0 */

#ifndef QT_TEXT_INPUT_METHOD_UNSTABLE_V1_SERVER_PROTOCOL_H
#define QT_TEXT_INPUT_METHOD_UNSTABLE_V1_SERVER_PROTOCOL_H

#include <stdint.h>
#include <stddef.h>
#include "wayland-server-core.h"

#ifdef  __cplusplus
extern "C" {
#endif

struct wl_client;
struct wl_resource;

/**
 * @page page_qt_text_input_method_unstable_v1 The qt_text_input_method_unstable_v1 protocol
 * @section page_ifaces_qt_text_input_method_unstable_v1 Interfaces
 * - @subpage page_iface_qt_text_input_method_v1 - text input
 * - @subpage page_iface_qt_text_input_method_manager_v1 - qt text input method manager
 * @section page_copyright_qt_text_input_method_unstable_v1 Copyright
 * <pre>
 *
 * Copyright © 2020 The Qt Company Ltd.
 *
 * Permission to use, copy, modify, distribute, and sell this
 * software and its documentation for any purpose is hereby granted
 * without fee, provided that the above copyright notice appear in
 * all copies and that both that copyright notice and this permission
 * notice appear in supporting documentation, and that the name of
 * the copyright holders not be used in advertising or publicity
 * pertaining to distribution of the software without specific,
 * written prior permission.  The copyright holders make no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied
 * warranty.
 *
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS
 * SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS, IN NO EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN
 * AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
 * ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF
 * THIS SOFTWARE.
 * </pre>
 */
struct qt_text_input_method_manager_v1;
struct qt_text_input_method_v1;
struct wl_seat;
struct wl_surface;

#ifndef QT_TEXT_INPUT_METHOD_V1_INTERFACE
#define QT_TEXT_INPUT_METHOD_V1_INTERFACE
/**
 * @page page_iface_qt_text_input_method_v1 qt_text_input_method_v1
 * @section page_iface_qt_text_input_method_v1_desc Description
 *
 * The qt_text_input_method interface represents input method events
 * associated with a seat, and is intended to exactly match the
 * internal events of the Qt framework.
 * @section page_iface_qt_text_input_method_v1_api API
 * See @ref iface_qt_text_input_method_v1.
 */
/**
 * @defgroup iface_qt_text_input_method_v1 The qt_text_input_method_v1 interface
 *
 * The qt_text_input_method interface represents input method events
 * associated with a seat, and is intended to exactly match the
 * internal events of the Qt framework.
 */
extern const struct wl_interface qt_text_input_method_v1_interface;
#endif
#ifndef QT_TEXT_INPUT_METHOD_MANAGER_V1_INTERFACE
#define QT_TEXT_INPUT_METHOD_MANAGER_V1_INTERFACE
/**
 * @page page_iface_qt_text_input_method_manager_v1 qt_text_input_method_manager_v1
 * @section page_iface_qt_text_input_method_manager_v1_desc Description
 *
 * Manages qt_text_input_method objects.
 * @section page_iface_qt_text_input_method_manager_v1_api API
 * See @ref iface_qt_text_input_method_manager_v1.
 */
/**
 * @defgroup iface_qt_text_input_method_manager_v1 The qt_text_input_method_manager_v1 interface
 *
 * Manages qt_text_input_method objects.
 */
extern const struct wl_interface qt_text_input_method_manager_v1_interface;
#endif

/**
 * @ingroup iface_qt_text_input_method_v1
 * @struct qt_text_input_method_v1_interface
 */
struct qt_text_input_method_v1_interface {
	/**
	 * Destroy the qt_text_input_method
	 *
	 * Destroy the qt_text_input_method object.
	 */
	void (*destroy)(struct wl_client *client,
			struct wl_resource *resource);
	/**
	 * enable input methods for surface
	 *
	 * Enable text input in a surface (usually when a text entry
	 * inside of it has focus).
	 *
	 * This can be called before or after a surface gets text (or
	 * keyboard) focus via the enter event. Text input to a surface is
	 * only active when it has the current text (or keyboard) focus and
	 * is enabled.
	 */
	void (*enable)(struct wl_client *client,
		       struct wl_resource *resource,
		       struct wl_resource *surface);
	/**
	 * disable input methods for surface
	 *
	 * Disable text input in a surface (typically when there is no
	 * focus on any text entry inside the surface).
	 */
	void (*disable)(struct wl_client *client,
			struct wl_resource *resource,
			struct wl_resource *surface);
	/**
	 * reset
	 *
	 * Request for the input method to reset. Corresponds to
	 * QInputMethod::reset().
	 */
	void (*reset)(struct wl_client *client,
		      struct wl_resource *resource);
	/**
	 * commit
	 *
	 * Request for the input method to commit its current content.
	 * Corresponds to QInputMethod::commit().
	 */
	void (*commit)(struct wl_client *client,
		       struct wl_resource *resource);
	/**
	 * invoke action
	 *
	 * Passes a mouse click or context menu request from the client
	 * to the server. Corresponds to QInputMethod::invokeAction().
	 */
	void (*invoke_action)(struct wl_client *client,
			      struct wl_resource *resource,
			      int32_t type,
			      int32_t cursor_position);
	/**
	 * update hints
	 *
	 * Notifies the server of the client's current input method
	 * hints.
	 */
	void (*update_hints)(struct wl_client *client,
			     struct wl_resource *resource,
			     int32_t hints);
	/**
	 * update cursor rectangle
	 *
	 * Notifies the server of the client's current cursor rectangle.
	 */
	void (*update_cursor_rectangle)(struct wl_client *client,
					struct wl_resource *resource,
					int32_t x,
					int32_t y,
					int32_t width,
					int32_t height);
	/**
	 * update cursor position
	 *
	 * Notifies the server of the client's current cursor position.
	 */
	void (*update_cursor_position)(struct wl_client *client,
				       struct wl_resource *resource,
				       int32_t cursor_position);
	/**
	 * update surrounding text
	 *
	 * Notifies the server of the client's current surrounding text
	 * and its offset in the complete text.
	 */
	void (*update_surrounding_text)(struct wl_client *client,
					struct wl_resource *resource,
					const char *surrounding_text,
					int32_t text_offset);
	/**
	 * update anchor position
	 *
	 * Notifies the server of the client's current anchor position.
	 */
	void (*update_anchor_position)(struct wl_client *client,
				       struct wl_resource *resource,
				       int32_t anchor_position);
	/**
	 * update absolute position
	 *
	 * Notifies the server of the client's current absolute cursor
	 * position.
	 */
	void (*update_absolute_position)(struct wl_client *client,
					 struct wl_resource *resource,
					 int32_t absolute_position);
	/**
	 * update preferred language
	 *
	 * Notifies the server of the client's current preferred
	 * language.
	 */
	void (*update_preferred_language)(struct wl_client *client,
					  struct wl_resource *resource,
					  const char *preferred_language);
	/**
	 * start update
	 *
	 * Starts an update sequence to notify the server that the
	 * client's state has changed. This is followed by any number of
	 * update requests for specific parts of the state and concluded by
	 * an end_update request.
	 */
	void (*start_update)(struct wl_client *client,
			     struct wl_resource *resource,
			     int32_t queries);
	/**
	 * end update
	 *
	 * Concludes the previously started update request.
	 */
	void (*end_update)(struct wl_client *client,
			   struct wl_resource *resource);
	/**
	 * show input panel
	 *
	 * Requests that the input panel of the input method is visible.
	 */
	void (*show_input_panel)(struct wl_client *client,
				 struct wl_resource *resource);
	/**
	 * hide input panel
	 *
	 * Requests that the input panel of the input method is not
	 * visible.
	 */
	void (*hide_input_panel)(struct wl_client *client,
				 struct wl_resource *resource);
	/**
	 * acknowledge input method
	 *
	 * Sent on receipt of an end_input_method_event to acknowledge
	 * that the client has received and handled the event.
	 */
	void (*acknowledge_input_method)(struct wl_client *client,
					 struct wl_resource *resource);
};

#define QT_TEXT_INPUT_METHOD_V1_ENTER 0
#define QT_TEXT_INPUT_METHOD_V1_LEAVE 1
#define QT_TEXT_INPUT_METHOD_V1_KEY 2
#define QT_TEXT_INPUT_METHOD_V1_START_INPUT_METHOD_EVENT 3
#define QT_TEXT_INPUT_METHOD_V1_INPUT_METHOD_EVENT_ATTRIBUTE 4
#define QT_TEXT_INPUT_METHOD_V1_END_INPUT_METHOD_EVENT 5
#define QT_TEXT_INPUT_METHOD_V1_VISIBLE_CHANGED 6
#define QT_TEXT_INPUT_METHOD_V1_KEYBOARD_RECTANGLE_CHANGED 7
#define QT_TEXT_INPUT_METHOD_V1_LOCALE_CHANGED 8
#define QT_TEXT_INPUT_METHOD_V1_INPUT_DIRECTION_CHANGED 9

/**
 * @ingroup iface_qt_text_input_method_v1
 */
#define QT_TEXT_INPUT_METHOD_V1_ENTER_SINCE_VERSION 1
/**
 * @ingroup iface_qt_text_input_method_v1
 */
#define QT_TEXT_INPUT_METHOD_V1_LEAVE_SINCE_VERSION 1
/**
 * @ingroup iface_qt_text_input_method_v1
 */
#define QT_TEXT_INPUT_METHOD_V1_KEY_SINCE_VERSION 1
/**
 * @ingroup iface_qt_text_input_method_v1
 */
#define QT_TEXT_INPUT_METHOD_V1_START_INPUT_METHOD_EVENT_SINCE_VERSION 1
/**
 * @ingroup iface_qt_text_input_method_v1
 */
#define QT_TEXT_INPUT_METHOD_V1_INPUT_METHOD_EVENT_ATTRIBUTE_SINCE_VERSION 1
/**
 * @ingroup iface_qt_text_input_method_v1
 */
#define QT_TEXT_INPUT_METHOD_V1_END_INPUT_METHOD_EVENT_SINCE_VERSION 1
/**
 * @ingroup iface_qt_text_input_method_v1
 */
#define QT_TEXT_INPUT_METHOD_V1_VISIBLE_CHANGED_SINCE_VERSION 1
/**
 * @ingroup iface_qt_text_input_method_v1
 */
#define QT_TEXT_INPUT_METHOD_V1_KEYBOARD_RECTANGLE_CHANGED_SINCE_VERSION 1
/**
 * @ingroup iface_qt_text_input_method_v1
 */
#define QT_TEXT_INPUT_METHOD_V1_LOCALE_CHANGED_SINCE_VERSION 1
/**
 * @ingroup iface_qt_text_input_method_v1
 */
#define QT_TEXT_INPUT_METHOD_V1_INPUT_DIRECTION_CHANGED_SINCE_VERSION 1

/**
 * @ingroup iface_qt_text_input_method_v1
 */
#define QT_TEXT_INPUT_METHOD_V1_DESTROY_SINCE_VERSION 1
/**
 * @ingroup iface_qt_text_input_method_v1
 */
#define QT_TEXT_INPUT_METHOD_V1_ENABLE_SINCE_VERSION 1
/**
 * @ingroup iface_qt_text_input_method_v1
 */
#define QT_TEXT_INPUT_METHOD_V1_DISABLE_SINCE_VERSION 1
/**
 * @ingroup iface_qt_text_input_method_v1
 */
#define QT_TEXT_INPUT_METHOD_V1_RESET_SINCE_VERSION 1
/**
 * @ingroup iface_qt_text_input_method_v1
 */
#define QT_TEXT_INPUT_METHOD_V1_COMMIT_SINCE_VERSION 1
/**
 * @ingroup iface_qt_text_input_method_v1
 */
#define QT_TEXT_INPUT_METHOD_V1_INVOKE_ACTION_SINCE_VERSION 1
/**
 * @ingroup iface_qt_text_input_method_v1
 */
#define QT_TEXT_INPUT_METHOD_V1_UPDATE_HINTS_SINCE_VERSION 1
/**
 * @ingroup iface_qt_text_input_method_v1
 */
#define QT_TEXT_INPUT_METHOD_V1_UPDATE_CURSOR_RECTANGLE_SINCE_VERSION 1
/**
 * @ingroup iface_qt_text_input_method_v1
 */
#define QT_TEXT_INPUT_METHOD_V1_UPDATE_CURSOR_POSITION_SINCE_VERSION 1
/**
 * @ingroup iface_qt_text_input_method_v1
 */
#define QT_TEXT_INPUT_METHOD_V1_UPDATE_SURROUNDING_TEXT_SINCE_VERSION 1
/**
 * @ingroup iface_qt_text_input_method_v1
 */
#define QT_TEXT_INPUT_METHOD_V1_UPDATE_ANCHOR_POSITION_SINCE_VERSION 1
/**
 * @ingroup iface_qt_text_input_method_v1
 */
#define QT_TEXT_INPUT_METHOD_V1_UPDATE_ABSOLUTE_POSITION_SINCE_VERSION 1
/**
 * @ingroup iface_qt_text_input_method_v1
 */
#define QT_TEXT_INPUT_METHOD_V1_UPDATE_PREFERRED_LANGUAGE_SINCE_VERSION 1
/**
 * @ingroup iface_qt_text_input_method_v1
 */
#define QT_TEXT_INPUT_METHOD_V1_START_UPDATE_SINCE_VERSION 1
/**
 * @ingroup iface_qt_text_input_method_v1
 */
#define QT_TEXT_INPUT_METHOD_V1_END_UPDATE_SINCE_VERSION 1
/**
 * @ingroup iface_qt_text_input_method_v1
 */
#define QT_TEXT_INPUT_METHOD_V1_SHOW_INPUT_PANEL_SINCE_VERSION 1
/**
 * @ingroup iface_qt_text_input_method_v1
 */
#define QT_TEXT_INPUT_METHOD_V1_HIDE_INPUT_PANEL_SINCE_VERSION 1
/**
 * @ingroup iface_qt_text_input_method_v1
 */
#define QT_TEXT_INPUT_METHOD_V1_ACKNOWLEDGE_INPUT_METHOD_SINCE_VERSION 1

/**
 * @ingroup iface_qt_text_input_method_v1
 * Sends an enter event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
qt_text_input_method_v1_send_enter(struct wl_resource *resource_, struct wl_resource *surface)
{
	wl_resource_post_event(resource_, QT_TEXT_INPUT_METHOD_V1_ENTER, surface);
}

/**
 * @ingroup iface_qt_text_input_method_v1
 * Sends an leave event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
qt_text_input_method_v1_send_leave(struct wl_resource *resource_, struct wl_resource *surface)
{
	wl_resource_post_event(resource_, QT_TEXT_INPUT_METHOD_V1_LEAVE, surface);
}

/**
 * @ingroup iface_qt_text_input_method_v1
 * Sends an key event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
qt_text_input_method_v1_send_key(struct wl_resource *resource_, int32_t type, int32_t key, int32_t modifiers, int32_t auto_repeat, int32_t count, int32_t native_scan_code, int32_t native_virtual_key, int32_t native_modifiers, const char *text)
{
	wl_resource_post_event(resource_, QT_TEXT_INPUT_METHOD_V1_KEY, type, key, modifiers, auto_repeat, count, native_scan_code, native_virtual_key, native_modifiers, text);
}

/**
 * @ingroup iface_qt_text_input_method_v1
 * Sends an start_input_method_event event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
qt_text_input_method_v1_send_start_input_method_event(struct wl_resource *resource_, uint32_t serial, int32_t surrounding_text_offset)
{
	wl_resource_post_event(resource_, QT_TEXT_INPUT_METHOD_V1_START_INPUT_METHOD_EVENT, serial, surrounding_text_offset);
}

/**
 * @ingroup iface_qt_text_input_method_v1
 * Sends an input_method_event_attribute event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
qt_text_input_method_v1_send_input_method_event_attribute(struct wl_resource *resource_, uint32_t serial, int32_t type, int32_t start, int32_t length, const char *value)
{
	wl_resource_post_event(resource_, QT_TEXT_INPUT_METHOD_V1_INPUT_METHOD_EVENT_ATTRIBUTE, serial, type, start, length, value);
}

/**
 * @ingroup iface_qt_text_input_method_v1
 * Sends an end_input_method_event event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
qt_text_input_method_v1_send_end_input_method_event(struct wl_resource *resource_, uint32_t serial, const char *commit_string, const char *preedit_string, int32_t replacement_start, int32_t replacement_length)
{
	wl_resource_post_event(resource_, QT_TEXT_INPUT_METHOD_V1_END_INPUT_METHOD_EVENT, serial, commit_string, preedit_string, replacement_start, replacement_length);
}

/**
 * @ingroup iface_qt_text_input_method_v1
 * Sends an visible_changed event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
qt_text_input_method_v1_send_visible_changed(struct wl_resource *resource_, int32_t visible)
{
	wl_resource_post_event(resource_, QT_TEXT_INPUT_METHOD_V1_VISIBLE_CHANGED, visible);
}

/**
 * @ingroup iface_qt_text_input_method_v1
 * Sends an keyboard_rectangle_changed event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
qt_text_input_method_v1_send_keyboard_rectangle_changed(struct wl_resource *resource_, wl_fixed_t x, wl_fixed_t y, wl_fixed_t width, wl_fixed_t height)
{
	wl_resource_post_event(resource_, QT_TEXT_INPUT_METHOD_V1_KEYBOARD_RECTANGLE_CHANGED, x, y, width, height);
}

/**
 * @ingroup iface_qt_text_input_method_v1
 * Sends an locale_changed event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
qt_text_input_method_v1_send_locale_changed(struct wl_resource *resource_, const char *locale_name)
{
	wl_resource_post_event(resource_, QT_TEXT_INPUT_METHOD_V1_LOCALE_CHANGED, locale_name);
}

/**
 * @ingroup iface_qt_text_input_method_v1
 * Sends an input_direction_changed event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
qt_text_input_method_v1_send_input_direction_changed(struct wl_resource *resource_, int32_t input_direction)
{
	wl_resource_post_event(resource_, QT_TEXT_INPUT_METHOD_V1_INPUT_DIRECTION_CHANGED, input_direction);
}

/**
 * @ingroup iface_qt_text_input_method_manager_v1
 * @struct qt_text_input_method_manager_v1_interface
 */
struct qt_text_input_method_manager_v1_interface {
	/**
	 * Destroy the qt_text_input_method_manager
	 *
	 * Destroy the qt_text_input_method_manager object.
	 */
	void (*destroy)(struct wl_client *client,
			struct wl_resource *resource);
	/**
	 * create a new text input method object
	 *
	 * Creates a new text-input-method object for a given seat.
	 */
	void (*get_text_input_method)(struct wl_client *client,
				      struct wl_resource *resource,
				      uint32_t id,
				      struct wl_resource *seat);
};


/**
 * @ingroup iface_qt_text_input_method_manager_v1
 */
#define QT_TEXT_INPUT_METHOD_MANAGER_V1_DESTROY_SINCE_VERSION 1
/**
 * @ingroup iface_qt_text_input_method_manager_v1
 */
#define QT_TEXT_INPUT_METHOD_MANAGER_V1_GET_TEXT_INPUT_METHOD_SINCE_VERSION 1

#ifdef  __cplusplus
}
#endif

#endif
