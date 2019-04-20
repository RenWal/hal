#ifndef GRAPHICS_NODE_H
#define GRAPHICS_NODE_H

#include "graph_widget/graphics_items/graphics_item.h"

class graphics_node : public graphics_item
{
public:
    struct visuals
    {
        QColor name_color;
        QColor type_color;
        QColor pin_color;
        QColor background_color;
        QColor border_color;
        QColor highlight_color;
        QVector<QColor> info_colors;

        // DRAW TYPE ENUM
    };

    graphics_node();

    virtual QRectF boundingRect() const Q_DECL_OVERRIDE;
    virtual QPainterPath shape() const Q_DECL_OVERRIDE;

    virtual QPointF get_input_pin_scene_position(const QString& type) const = 0;
    virtual QPointF get_output_pin_scene_position(const QString& type) const = 0;

//    std::string get_input_pin_type_at_position(const size_t pos) const = 0;
//    std::string get_output_pin_type_at_position(const size_t pos) const = 0;

//    qreal x_offset() const;
//    qreal y_offset() const;

    qreal width() const;
    qreal height() const;

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant& value) Q_DECL_OVERRIDE;

//    qreal m_x_offset;
//    qreal m_y_offset;

    qreal m_width;
    qreal m_height;

//    QString m_name;
//    QString m_type;
};

#endif // GRAPHICS_NODE_H
