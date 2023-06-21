// This file was generated by qtwaylandscanner
// source file is /home/udrc/qt5/qtwayland/src/compositor/../extensions/qt-text-input-method-unstable-v1.xml

#ifndef QT_WAYLAND_SERVER_QT_TEXT_INPUT_METHOD_UNSTABLE_V1
#define QT_WAYLAND_SERVER_QT_TEXT_INPUT_METHOD_UNSTABLE_V1

#include "wayland-server-core.h"
#include <QtWaylandCompositor/private/wayland-qt-text-input-method-unstable-v1-server-protocol.h>
#include <QByteArray>
#include <QMultiMap>
#include <QString>

#ifndef WAYLAND_VERSION_CHECK
#define WAYLAND_VERSION_CHECK(major, minor, micro) \
    ((WAYLAND_VERSION_MAJOR > (major)) || \
    (WAYLAND_VERSION_MAJOR == (major) && WAYLAND_VERSION_MINOR > (minor)) || \
    (WAYLAND_VERSION_MAJOR == (major) && WAYLAND_VERSION_MINOR == (minor) && WAYLAND_VERSION_MICRO >= (micro)))
#endif

QT_BEGIN_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_GCC("-Wmissing-field-initializers")
QT_WARNING_DISABLE_CLANG("-Wmissing-field-initializers")
#if !defined(Q_WAYLAND_SERVER_QT_TEXT_INPUT_METHOD_UNSTABLE_V1_EXPORT)
#  if defined(QT_SHARED) && !defined(QT_STATIC)
#    if defined(QT_BUILD_WAYLANDCOMPOSITOR_LIB)
#      define Q_WAYLAND_SERVER_QT_TEXT_INPUT_METHOD_UNSTABLE_V1_EXPORT Q_DECL_EXPORT
#    else
#      define Q_WAYLAND_SERVER_QT_TEXT_INPUT_METHOD_UNSTABLE_V1_EXPORT Q_DECL_IMPORT
#    endif
#  else
#    define Q_WAYLAND_SERVER_QT_TEXT_INPUT_METHOD_UNSTABLE_V1_EXPORT
#  endif
#endif

namespace QtWaylandServer {
    class Q_WAYLAND_SERVER_QT_TEXT_INPUT_METHOD_UNSTABLE_V1_EXPORT qt_text_input_method_v1
    {
    public:
        qt_text_input_method_v1(struct ::wl_client *client, uint32_t id, int version);
        qt_text_input_method_v1(struct ::wl_display *display, int version);
        qt_text_input_method_v1(struct ::wl_resource *resource);
        qt_text_input_method_v1();

        virtual ~qt_text_input_method_v1();

        class Resource
        {
        public:
            Resource() : text_input_method_v1_object(nullptr), handle(nullptr) {}
            virtual ~Resource() {}

            qt_text_input_method_v1 *text_input_method_v1_object;
            qt_text_input_method_v1 *object() { return text_input_method_v1_object; } 
            struct ::wl_resource *handle;

            struct ::wl_client *client() const { return wl_resource_get_client(handle); }
            int version() const { return wl_resource_get_version(handle); }

            static Resource *fromResource(struct ::wl_resource *resource);
        };

        void init(struct ::wl_client *client, uint32_t id, int version);
        void init(struct ::wl_display *display, int version);
        void init(struct ::wl_resource *resource);

        Resource *add(struct ::wl_client *client, int version);
        Resource *add(struct ::wl_client *client, uint32_t id, int version);
        Resource *add(struct wl_list *resource_list, struct ::wl_client *client, uint32_t id, int version);

        Resource *resource() { return m_resource; }
        const Resource *resource() const { return m_resource; }

        QMultiMap<struct ::wl_client*, Resource*> resourceMap() { return m_resource_map; }
        const QMultiMap<struct ::wl_client*, Resource*> resourceMap() const { return m_resource_map; }

        bool isGlobal() const { return m_global != nullptr; }
        bool isResource() const { return m_resource != nullptr; }

        static const struct ::wl_interface *interface();
        static QByteArray interfaceName() { return interface()->name; }
        static int interfaceVersion() { return interface()->version; }


        void send_enter(struct ::wl_resource *surface);
        void send_enter(struct ::wl_resource *resource, struct ::wl_resource *surface);
        void send_leave(struct ::wl_resource *surface);
        void send_leave(struct ::wl_resource *resource, struct ::wl_resource *surface);
        void send_key(int32_t type, int32_t key, int32_t modifiers, int32_t auto_repeat, int32_t count, int32_t native_scan_code, int32_t native_virtual_key, int32_t native_modifiers, const QString &text);
        void send_key(struct ::wl_resource *resource, int32_t type, int32_t key, int32_t modifiers, int32_t auto_repeat, int32_t count, int32_t native_scan_code, int32_t native_virtual_key, int32_t native_modifiers, const QString &text);
        void send_start_input_method_event(uint32_t serial, int32_t surrounding_text_offset);
        void send_start_input_method_event(struct ::wl_resource *resource, uint32_t serial, int32_t surrounding_text_offset);
        void send_input_method_event_attribute(uint32_t serial, int32_t type, int32_t start, int32_t length, const QString &value);
        void send_input_method_event_attribute(struct ::wl_resource *resource, uint32_t serial, int32_t type, int32_t start, int32_t length, const QString &value);
        void send_end_input_method_event(uint32_t serial, const QString &commit_string, const QString &preedit_string, int32_t replacement_start, int32_t replacement_length);
        void send_end_input_method_event(struct ::wl_resource *resource, uint32_t serial, const QString &commit_string, const QString &preedit_string, int32_t replacement_start, int32_t replacement_length);
        void send_visible_changed(int32_t visible);
        void send_visible_changed(struct ::wl_resource *resource, int32_t visible);
        void send_keyboard_rectangle_changed(wl_fixed_t x, wl_fixed_t y, wl_fixed_t width, wl_fixed_t height);
        void send_keyboard_rectangle_changed(struct ::wl_resource *resource, wl_fixed_t x, wl_fixed_t y, wl_fixed_t width, wl_fixed_t height);
        void send_locale_changed(const QString &locale_name);
        void send_locale_changed(struct ::wl_resource *resource, const QString &locale_name);
        void send_input_direction_changed(int32_t input_direction);
        void send_input_direction_changed(struct ::wl_resource *resource, int32_t input_direction);

    protected:
        virtual Resource *text_input_method_v1_allocate();

        virtual void text_input_method_v1_bind_resource(Resource *resource);
        virtual void text_input_method_v1_destroy_resource(Resource *resource);

        virtual void text_input_method_v1_destroy(Resource *resource);
        virtual void text_input_method_v1_enable(Resource *resource, struct ::wl_resource *surface);
        virtual void text_input_method_v1_disable(Resource *resource, struct ::wl_resource *surface);
        virtual void text_input_method_v1_reset(Resource *resource);
        virtual void text_input_method_v1_commit(Resource *resource);
        virtual void text_input_method_v1_invoke_action(Resource *resource, int32_t type, int32_t cursor_position);
        virtual void text_input_method_v1_update_hints(Resource *resource, int32_t hints);
        virtual void text_input_method_v1_update_cursor_rectangle(Resource *resource, int32_t x, int32_t y, int32_t width, int32_t height);
        virtual void text_input_method_v1_update_cursor_position(Resource *resource, int32_t cursor_position);
        virtual void text_input_method_v1_update_surrounding_text(Resource *resource, const QString &surrounding_text, int32_t text_offset);
        virtual void text_input_method_v1_update_anchor_position(Resource *resource, int32_t anchor_position);
        virtual void text_input_method_v1_update_absolute_position(Resource *resource, int32_t absolute_position);
        virtual void text_input_method_v1_update_preferred_language(Resource *resource, const QString &preferred_language);
        virtual void text_input_method_v1_start_update(Resource *resource, int32_t queries);
        virtual void text_input_method_v1_end_update(Resource *resource);
        virtual void text_input_method_v1_show_input_panel(Resource *resource);
        virtual void text_input_method_v1_hide_input_panel(Resource *resource);
        virtual void text_input_method_v1_acknowledge_input_method(Resource *resource);

    private:
        static void bind_func(struct ::wl_client *client, void *data, uint32_t version, uint32_t id);
        static void destroy_func(struct ::wl_resource *client_resource);
        static void display_destroy_func(struct ::wl_listener *listener, void *data);

        Resource *bind(struct ::wl_client *client, uint32_t id, int version);
        Resource *bind(struct ::wl_resource *handle);

        static const struct ::qt_text_input_method_v1_interface m_qt_text_input_method_v1_interface;

        static void handle_destroy(
            ::wl_client *client,
            struct wl_resource *resource);
        static void handle_enable(
            ::wl_client *client,
            struct wl_resource *resource,
            struct ::wl_resource *surface);
        static void handle_disable(
            ::wl_client *client,
            struct wl_resource *resource,
            struct ::wl_resource *surface);
        static void handle_reset(
            ::wl_client *client,
            struct wl_resource *resource);
        static void handle_commit(
            ::wl_client *client,
            struct wl_resource *resource);
        static void handle_invoke_action(
            ::wl_client *client,
            struct wl_resource *resource,
            int32_t type,
            int32_t cursor_position);
        static void handle_update_hints(
            ::wl_client *client,
            struct wl_resource *resource,
            int32_t hints);
        static void handle_update_cursor_rectangle(
            ::wl_client *client,
            struct wl_resource *resource,
            int32_t x,
            int32_t y,
            int32_t width,
            int32_t height);
        static void handle_update_cursor_position(
            ::wl_client *client,
            struct wl_resource *resource,
            int32_t cursor_position);
        static void handle_update_surrounding_text(
            ::wl_client *client,
            struct wl_resource *resource,
            const char *surrounding_text,
            int32_t text_offset);
        static void handle_update_anchor_position(
            ::wl_client *client,
            struct wl_resource *resource,
            int32_t anchor_position);
        static void handle_update_absolute_position(
            ::wl_client *client,
            struct wl_resource *resource,
            int32_t absolute_position);
        static void handle_update_preferred_language(
            ::wl_client *client,
            struct wl_resource *resource,
            const char *preferred_language);
        static void handle_start_update(
            ::wl_client *client,
            struct wl_resource *resource,
            int32_t queries);
        static void handle_end_update(
            ::wl_client *client,
            struct wl_resource *resource);
        static void handle_show_input_panel(
            ::wl_client *client,
            struct wl_resource *resource);
        static void handle_hide_input_panel(
            ::wl_client *client,
            struct wl_resource *resource);
        static void handle_acknowledge_input_method(
            ::wl_client *client,
            struct wl_resource *resource);

        QMultiMap<struct ::wl_client*, Resource*> m_resource_map;
        Resource *m_resource;
        struct ::wl_global *m_global;
        struct DisplayDestroyedListener : ::wl_listener {
            qt_text_input_method_v1 *parent;
        };
        DisplayDestroyedListener m_displayDestroyedListener;
    };

    class Q_WAYLAND_SERVER_QT_TEXT_INPUT_METHOD_UNSTABLE_V1_EXPORT qt_text_input_method_manager_v1
    {
    public:
        qt_text_input_method_manager_v1(struct ::wl_client *client, uint32_t id, int version);
        qt_text_input_method_manager_v1(struct ::wl_display *display, int version);
        qt_text_input_method_manager_v1(struct ::wl_resource *resource);
        qt_text_input_method_manager_v1();

        virtual ~qt_text_input_method_manager_v1();

        class Resource
        {
        public:
            Resource() : text_input_method_manager_v1_object(nullptr), handle(nullptr) {}
            virtual ~Resource() {}

            qt_text_input_method_manager_v1 *text_input_method_manager_v1_object;
            qt_text_input_method_manager_v1 *object() { return text_input_method_manager_v1_object; } 
            struct ::wl_resource *handle;

            struct ::wl_client *client() const { return wl_resource_get_client(handle); }
            int version() const { return wl_resource_get_version(handle); }

            static Resource *fromResource(struct ::wl_resource *resource);
        };

        void init(struct ::wl_client *client, uint32_t id, int version);
        void init(struct ::wl_display *display, int version);
        void init(struct ::wl_resource *resource);

        Resource *add(struct ::wl_client *client, int version);
        Resource *add(struct ::wl_client *client, uint32_t id, int version);
        Resource *add(struct wl_list *resource_list, struct ::wl_client *client, uint32_t id, int version);

        Resource *resource() { return m_resource; }
        const Resource *resource() const { return m_resource; }

        QMultiMap<struct ::wl_client*, Resource*> resourceMap() { return m_resource_map; }
        const QMultiMap<struct ::wl_client*, Resource*> resourceMap() const { return m_resource_map; }

        bool isGlobal() const { return m_global != nullptr; }
        bool isResource() const { return m_resource != nullptr; }

        static const struct ::wl_interface *interface();
        static QByteArray interfaceName() { return interface()->name; }
        static int interfaceVersion() { return interface()->version; }


    protected:
        virtual Resource *text_input_method_manager_v1_allocate();

        virtual void text_input_method_manager_v1_bind_resource(Resource *resource);
        virtual void text_input_method_manager_v1_destroy_resource(Resource *resource);

        virtual void text_input_method_manager_v1_destroy(Resource *resource);
        virtual void text_input_method_manager_v1_get_text_input_method(Resource *resource, uint32_t id, struct ::wl_resource *seat);

    private:
        static void bind_func(struct ::wl_client *client, void *data, uint32_t version, uint32_t id);
        static void destroy_func(struct ::wl_resource *client_resource);
        static void display_destroy_func(struct ::wl_listener *listener, void *data);

        Resource *bind(struct ::wl_client *client, uint32_t id, int version);
        Resource *bind(struct ::wl_resource *handle);

        static const struct ::qt_text_input_method_manager_v1_interface m_qt_text_input_method_manager_v1_interface;

        static void handle_destroy(
            ::wl_client *client,
            struct wl_resource *resource);
        static void handle_get_text_input_method(
            ::wl_client *client,
            struct wl_resource *resource,
            uint32_t id,
            struct ::wl_resource *seat);

        QMultiMap<struct ::wl_client*, Resource*> m_resource_map;
        Resource *m_resource;
        struct ::wl_global *m_global;
        struct DisplayDestroyedListener : ::wl_listener {
            qt_text_input_method_manager_v1 *parent;
        };
        DisplayDestroyedListener m_displayDestroyedListener;
    };
}

QT_WARNING_POP
QT_END_NAMESPACE

#endif
