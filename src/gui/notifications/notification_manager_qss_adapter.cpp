#include "notifications/notification_manager_qss_adapter.h"

notification_manager_qss_adapter::notification_manager_qss_adapter(QWidget* parent) : QWidget(parent)
{
    //DEFAULT VALUES
    m_x_offset = 20;
    m_y_offset = 20;
    m_spacing  = 10;

    ensurePolished();
}

int notification_manager_qss_adapter::x_offset() const
{
    return m_x_offset;
}

int notification_manager_qss_adapter::y_offset() const
{
    return m_y_offset;
}

int notification_manager_qss_adapter::spacing() const
{
    return m_spacing;
}

void notification_manager_qss_adapter::set_x_offset(const int offset)
{
    m_x_offset = offset;
}

void notification_manager_qss_adapter::set_y_offset(const int offset)
{
    m_y_offset = offset;
}

void notification_manager_qss_adapter::set_spacing(const int spacing)
{
    m_spacing = spacing;
}
