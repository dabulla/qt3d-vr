/****************************************************************************
**
** Copyright (C) 2014 Klaralvdalens Datakonsult AB (KDAB).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the Qt3D module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QT3DRENDER_RENDER_QUICK_QUICK3DTECHNIQUE_H
#define QT3DRENDER_RENDER_QUICK_QUICK3DTECHNIQUE_H

#include <Qt3DQuickRender/qt3dquickrender_global.h>
#include <Qt3DRender/qtechnique.h>
#include <QQmlListProperty>

QT_BEGIN_NAMESPACE

namespace Qt3DRender {
namespace Render {
namespace Quick {

class QT3DQUICKRENDERSHARED_EXPORT Quick3DTechnique : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Qt3DRender::QAnnotation> annotations READ annotationList)
    Q_PROPERTY(QQmlListProperty<Qt3DRender::QRenderPass> renderPasses READ renderPassList)
    Q_PROPERTY(QQmlListProperty<Qt3DRender::QParameter> parameters READ parameterList)
public:
    explicit Quick3DTechnique(QObject *parent = 0);

    QQmlListProperty<QAnnotation> annotationList();
    QQmlListProperty<QRenderPass> renderPassList();
    QQmlListProperty<QParameter> parameterList();

    // Use QAbstractTechnique when it has been properly defined
    inline QTechnique *parentTechnique() const { return qobject_cast<QTechnique*>(parent()); }

private:

    static void appendParameter(QQmlListProperty<QParameter> *list, QParameter *param);
    static QParameter *parameterAt(QQmlListProperty<QParameter> *list, int index);
    static int parametersCount(QQmlListProperty<QParameter> *list);
    static void clearParameterList(QQmlListProperty<QParameter> *list);

    static void appendAnnotation(QQmlListProperty<QAnnotation> *list, QAnnotation *Annotation);
    static QAnnotation *annotationAt(QQmlListProperty<QAnnotation> *list, int index);
    static int annotationCount(QQmlListProperty<QAnnotation> *list);
    static void clearAnnotationList(QQmlListProperty<QAnnotation> *list);

    static void appendRenderPass(QQmlListProperty<QRenderPass> *list, QRenderPass* renderPass);
    static QRenderPass *renderPassAt(QQmlListProperty<QRenderPass> *list, int index);
    static int renderPassCount(QQmlListProperty<QRenderPass> *list);
    static void clearRenderPasses( QQmlListProperty<QRenderPass> *list);
};

} // namespace Quick
} // namespace Render
} // namespace Qt3DRender

QT_END_NAMESPACE

#endif // QT3DRENDER_RENDER_QUICK_QUICK3DTECHNIQUE_H