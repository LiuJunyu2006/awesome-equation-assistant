#include "widgets/katexviewer.h"

KatexViewer::KatexViewer(QWidget* parent) : QWidget(parent) {
    view = new QWebEngineView;
    layout = new QFormLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setWidget(0, QFormLayout::SpanningRole, view);
    addContent("\\KaTeX");
    flush();
}

KatexViewer::~KatexViewer() {
    delete view;
    delete layout;
}

void KatexViewer::clearContent() {
    content.clear();
    flush();
}

void KatexViewer::addContent(const QString& str) {
    content += "\\(" + str + "\\)\n";
    flush();
}

void KatexViewer::flush() {
    view->setHtml(R"(<!DOCTYPE html>
<!-- KaTeX requires the use of the HTML5 doctype. Without it, KaTeX may not render properly -->
<html>

<head>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/katex@0.16.4/dist/katex.min.css"
        integrity="sha384-vKruj+a13U8yHIkAyGgK1J3ArTLzrFGBbBc0tDp4ad/EyewESeXE/Iv67Aj8gKZ0" crossorigin="anonymous">

    <!-- The loading of KaTeX is deferred to speed up page rendering -->
    <script defer src="https://cdn.jsdelivr.net/npm/katex@0.16.4/dist/katex.min.js"
        integrity="sha384-PwRUT/YqbnEjkZO0zZxNqcxACrXe+j766U2amXcgMg5457rve2Y7I6ZJSm2A0mS4"
        crossorigin="anonymous"></script>

    <!-- To automatically render math in text elements, include the auto-render extension: -->
    <script defer src="https://cdn.jsdelivr.net/npm/katex@0.16.4/dist/contrib/auto-render.min.js"
        integrity="sha384-+VBxd3r6XgURycqtZ117nYw44OOcIax56Z4dCRWbxyPt0Koah1uHoK0o4+/RRE05" crossorigin="anonymous"
        onload="renderMathInElement(document.body);"></script>
</head>
<body>
)" + content + R"(</body>

</html>)");
}