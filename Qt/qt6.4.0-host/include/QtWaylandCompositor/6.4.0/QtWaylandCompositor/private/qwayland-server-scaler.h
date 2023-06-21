// This file was generated by qtwaylandscanner
// source file is /home/udrc/qt5/qtwayland/src/compositor/../3rdparty/protocol/scaler.xml

#ifndef QT_WAYLAND_SERVER_SCALER
#define QT_WAYLAND_SERVER_SCALER

#include "wayland-server-core.h"
#include <QtWaylandCompositor/private/wayland-scaler-server-protocol.h>
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
#if !defined(Q_WAYLAND_SERVER_SCALER_EXPORT)
#  if defined(QT_SHARED) && !defined(QT_STATIC)
#    if defined(QT_BUILD_WAYLANDCOMPOSITOR_LIB)
#      define Q_WAYLAND_SERVER_SCALER_EXPORT Q_DECL_EXPORT
#    else
#      define Q_WAYLAND_SERVER_SCALER_EXPORT Q_DECL_IMPORT
#    endif
#  else
#    define Q_WAYLAND_SERVER_SCALER_EXPORT
#  endif
#endif

namespace QtWaylandServer {
    class Q_WAYLAND_SERVER_SCALER_EXPORT wl_scaler
    {
    public:
        wl_scaler(struct ::wl_client *client, uint32_t id, int version);
        wl_scaler(struct ::wl_display *display, int version);
        wl_scaler(struct ::wl_resource *resource);
        wl_scaler();

        virtual ~wl_scaler();

        class Resource
        {
        public:
            Resource() : scaler_object(nullptr), handle(nullptr) {}
            virtual ~Resource() {}

            wl_scaler *scaler_object;
            wl_scaler *object() { return scaler_object; } 
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


        enum error {
            error_viewport_exists = 0, // the surface already has a viewport object associated
        };

    protected:
        virtual Resource *scaler_allocate();

        virtual void scaler_bind_resource(Resource *resource);
        virtual void scaler_destroy_resource(Resource *resource);

        virtual void scaler_destroy(Resource *resource);
        virtual void scaler_get_viewport(Resource *resource, uint32_t id, struct ::wl_resource *surface);

    private:
        static void bind_func(struct ::wl_client *client, void *data, uint32_t version, uint32_t id);
        static void destroy_func(struct ::wl_resource *client_resource);
        static void display_destroy_func(struct ::wl_listener *listener, void *data);

        Resource *bind(struct ::wl_client *client, uint32_t id, int version);
        Resource *bind(struct ::wl_resource *handle);

        static const struct ::wl_scaler_interface m_wl_scaler_interface;

        static void handle_destroy(
            ::wl_client *client,
            struct wl_resource *resource);
        static void handle_get_viewport(
            ::wl_client *client,
            struct wl_resource *resource,
            uint32_t id,
            struct ::wl_resource *surface);

        QMultiMap<struct ::wl_client*, Resource*> m_resource_map;
        Resource *m_resource;
        struct ::wl_global *m_global;
        struct DisplayDestroyedListener : ::wl_listener {
            wl_scaler *parent;
        };
        DisplayDestroyedListener m_displayDestroyedListener;
    };

    class Q_WAYLAND_SERVER_SCALER_EXPORT wl_viewport
    {
    public:
        wl_viewport(struct ::wl_client *client, uint32_t id, int version);
        wl_viewport(struct ::wl_display *display, int version);
        wl_viewport(struct ::wl_resource *resource);
        wl_viewport();

        virtual ~wl_viewport();

        class Resource
        {
        public:
            Resource() : viewport_object(nullptr), handle(nullptr) {}
            virtual ~Resource() {}

            wl_viewport *viewport_object;
            wl_viewport *object() { return viewport_object; } 
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


        enum error {
            error_bad_value = 0, // negative or zero values in width or height
        };

    protected:
        virtual Resource *viewport_allocate();

        virtual void viewport_bind_resource(Resource *resource);
        virtual void viewport_destroy_resource(Resource *resource);

        virtual void viewport_destroy(Resource *resource);
        virtual void viewport_set(Resource *resource, wl_fixed_t src_x, wl_fixed_t src_y, wl_fixed_t src_width, wl_fixed_t src_height, int32_t dst_width, int32_t dst_height);
        virtual void viewport_set_source(Resource *resource, wl_fixed_t x, wl_fixed_t y, wl_fixed_t width, wl_fixed_t height);
        virtual void viewport_set_destination(Resource *resource, int32_t width, int32_t height);

    private:
        static void bind_func(struct ::wl_client *client, void *data, uint32_t version, uint32_t id);
        static void destroy_func(struct ::wl_resource *client_resource);
        static void display_destroy_func(struct ::wl_listener *listener, void *data);

        Resource *bind(struct ::wl_client *client, uint32_t id, int version);
        Resource *bind(struct ::wl_resource *handle);

        static const struct ::wl_viewport_interface m_wl_viewport_interface;

        static void handle_destroy(
            ::wl_client *client,
            struct wl_resource *resource);
        static void handle_set(
            ::wl_client *client,
            struct wl_resource *resource,
            wl_fixed_t src_x,
            wl_fixed_t src_y,
            wl_fixed_t src_width,
            wl_fixed_t src_height,
            int32_t dst_width,
            int32_t dst_height);
        static void handle_set_source(
            ::wl_client *client,
            struct wl_resource *resource,
            wl_fixed_t x,
            wl_fixed_t y,
            wl_fixed_t width,
            wl_fixed_t height);
        static void handle_set_destination(
            ::wl_client *client,
            struct wl_resource *resource,
            int32_t width,
            int32_t height);

        QMultiMap<struct ::wl_client*, Resource*> m_resource_map;
        Resource *m_resource;
        struct ::wl_global *m_global;
        struct DisplayDestroyedListener : ::wl_listener {
            wl_viewport *parent;
        };
        DisplayDestroyedListener m_displayDestroyedListener;
    };
}

QT_WARNING_POP
QT_END_NAMESPACE

#endif
