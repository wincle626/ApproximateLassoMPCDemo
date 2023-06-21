// This file was generated by qtwaylandscanner
// source file is /home/udrc/qt5/qtwayland/src/client/../3rdparty/protocol/text-input-unstable-v4-wip.xml

#ifndef QT_WAYLAND_TEXT_INPUT_UNSTABLE_V4_WIP
#define QT_WAYLAND_TEXT_INPUT_UNSTABLE_V4_WIP

#include <QtWaylandClient/private/wayland-text-input-unstable-v4-wip-client-protocol.h>
#include <QByteArray>
#include <QString>

struct wl_registry;

QT_BEGIN_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_GCC("-Wmissing-field-initializers")
#if !defined(Q_WAYLAND_CLIENT_TEXT_INPUT_UNSTABLE_V4_WIP_EXPORT)
#  if defined(QT_SHARED) && !defined(QT_STATIC)
#    if defined(QT_BUILD_WAYLANDCLIENT_LIB)
#      define Q_WAYLAND_CLIENT_TEXT_INPUT_UNSTABLE_V4_WIP_EXPORT Q_DECL_EXPORT
#    else
#      define Q_WAYLAND_CLIENT_TEXT_INPUT_UNSTABLE_V4_WIP_EXPORT Q_DECL_IMPORT
#    endif
#  else
#    define Q_WAYLAND_CLIENT_TEXT_INPUT_UNSTABLE_V4_WIP_EXPORT
#  endif
#endif

namespace QtWayland {
    class Q_WAYLAND_CLIENT_TEXT_INPUT_UNSTABLE_V4_WIP_EXPORT zwp_text_input_v4
    {
    public:
        zwp_text_input_v4(struct ::wl_registry *registry, uint32_t id, int version);
        zwp_text_input_v4(struct ::zwp_text_input_v4 *object);
        zwp_text_input_v4();

        virtual ~zwp_text_input_v4();

        void init(struct ::wl_registry *registry, uint32_t id, int version);
        void init(struct ::zwp_text_input_v4 *object);

        struct ::zwp_text_input_v4 *object() { return m_zwp_text_input_v4; }
        const struct ::zwp_text_input_v4 *object() const { return m_zwp_text_input_v4; }
        static zwp_text_input_v4 *fromObject(struct ::zwp_text_input_v4 *object);

        bool isInitialized() const;

        uint32_t version() const;
        static const struct ::wl_interface *interface();

        enum change_cause {
            change_cause_input_method = 0, // input method caused the change
            change_cause_other = 1, // something else than the input method caused the change
        };

        enum content_hint {
            content_hint_none = 0x0, // no special behavior
            content_hint_completion = 0x1, // suggest word completions
            content_hint_spellcheck = 0x2, // suggest word corrections
            content_hint_auto_capitalization = 0x4, // switch to uppercase letters at the start of a sentence
            content_hint_lowercase = 0x8, // prefer lowercase letters
            content_hint_uppercase = 0x10, // prefer uppercase letters
            content_hint_titlecase = 0x20, // prefer casing for titles and headings (can be language dependent)
            content_hint_hidden_text = 0x40, // characters should be hidden
            content_hint_sensitive_data = 0x80, // typed text should not be stored
            content_hint_latin = 0x100, // just Latin characters should be entered
            content_hint_multiline = 0x200, // the text input is multiline
        };

        enum content_purpose {
            content_purpose_normal = 0, // default input, allowing all characters
            content_purpose_alpha = 1, // allow only alphabetic characters
            content_purpose_digits = 2, // allow only digits
            content_purpose_number = 3, // input a number (including decimal separator and sign)
            content_purpose_phone = 4, // input a phone number
            content_purpose_url = 5, // input an URL
            content_purpose_email = 6, // input an email address
            content_purpose_name = 7, // input a name of a person
            content_purpose_password = 8, // input a password (combine with sensitive_data hint)
            content_purpose_pin = 9, // input is a numeric password (combine with sensitive_data hint)
            content_purpose_date = 10, // input a date
            content_purpose_time = 11, // input a time
            content_purpose_datetime = 12, // input a date and time
            content_purpose_terminal = 13, // input for a terminal
        };

        enum commit_mode {
            commit_mode_clear = 0, // pre-edit text is cleared
            commit_mode_commit = 1, // pre-edit text is committed
        };

        void destroy();
        void enable();
        void disable();
        void set_surrounding_text(const QString &text, int32_t cursor, int32_t anchor);
        void set_text_change_cause(uint32_t cause);
        void set_content_type(uint32_t hint, uint32_t purpose);
        void set_cursor_rectangle(int32_t x, int32_t y, int32_t width, int32_t height);
        void commit();

    protected:
        virtual void zwp_text_input_v4_enter(struct ::wl_surface *surface);
        virtual void zwp_text_input_v4_leave(struct ::wl_surface *surface);
        virtual void zwp_text_input_v4_preedit_string(const QString &text, int32_t cursor_begin, int32_t cursor_end);
        virtual void zwp_text_input_v4_commit_string(const QString &text);
        virtual void zwp_text_input_v4_delete_surrounding_text(uint32_t before_length, uint32_t after_length);
        virtual void zwp_text_input_v4_done(uint32_t serial);
        virtual void zwp_text_input_v4_preedit_commit_mode(uint32_t mode);

    private:
        void init_listener();
        static const struct zwp_text_input_v4_listener m_zwp_text_input_v4_listener;
        static void handle_enter(
            void *data,
            struct ::zwp_text_input_v4 *object,
            struct ::wl_surface *surface);
        static void handle_leave(
            void *data,
            struct ::zwp_text_input_v4 *object,
            struct ::wl_surface *surface);
        static void handle_preedit_string(
            void *data,
            struct ::zwp_text_input_v4 *object,
            const char *text,
            int32_t cursor_begin,
            int32_t cursor_end);
        static void handle_commit_string(
            void *data,
            struct ::zwp_text_input_v4 *object,
            const char *text);
        static void handle_delete_surrounding_text(
            void *data,
            struct ::zwp_text_input_v4 *object,
            uint32_t before_length,
            uint32_t after_length);
        static void handle_done(
            void *data,
            struct ::zwp_text_input_v4 *object,
            uint32_t serial);
        static void handle_preedit_commit_mode(
            void *data,
            struct ::zwp_text_input_v4 *object,
            uint32_t mode);
        struct ::zwp_text_input_v4 *m_zwp_text_input_v4;
    };

    class Q_WAYLAND_CLIENT_TEXT_INPUT_UNSTABLE_V4_WIP_EXPORT zwp_text_input_manager_v4
    {
    public:
        zwp_text_input_manager_v4(struct ::wl_registry *registry, uint32_t id, int version);
        zwp_text_input_manager_v4(struct ::zwp_text_input_manager_v4 *object);
        zwp_text_input_manager_v4();

        virtual ~zwp_text_input_manager_v4();

        void init(struct ::wl_registry *registry, uint32_t id, int version);
        void init(struct ::zwp_text_input_manager_v4 *object);

        struct ::zwp_text_input_manager_v4 *object() { return m_zwp_text_input_manager_v4; }
        const struct ::zwp_text_input_manager_v4 *object() const { return m_zwp_text_input_manager_v4; }
        static zwp_text_input_manager_v4 *fromObject(struct ::zwp_text_input_manager_v4 *object);

        bool isInitialized() const;

        uint32_t version() const;
        static const struct ::wl_interface *interface();

        void destroy();
        struct ::zwp_text_input_v4 *get_text_input(struct ::wl_seat *seat);

    private:
        struct ::zwp_text_input_manager_v4 *m_zwp_text_input_manager_v4;
    };
}

QT_WARNING_POP
QT_END_NAMESPACE

#endif
