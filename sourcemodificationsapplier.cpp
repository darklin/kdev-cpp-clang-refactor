/*
 * Copyright (c) 2013 Maciej Cencora <m.cencora@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#include "sourcemodificationsapplier.hpp"

#include <KTextEditor/Document>

namespace
{
using KTextEditor::Range;
Range createRange(const SourceLocation& from, const SourceLocation& to)
{
    return Range(from.row, from.col, to.row, to.col);
}

void applySingleChange(DocumentAdapter& doc, const SourceReplacement& r)
{
    auto range = createRange(r.from, r.to);
    doc.replaceText(range, QString::fromAscii(r.text.c_str()));
}
}

void SourceModificationsApplier::apply(DocumentAdapter& doc, const SourceReplacements& changes)
{
    for (auto& c : changes)
        applySingleChange(doc, c);
}

DocumentAdapter::DocumentAdapter(KTextEditor::Document* d) : doc(d)
{
    doc->startEditing();
}
DocumentAdapter::~DocumentAdapter()
{
    doc->endEditing();
}
bool DocumentAdapter::replaceText(const KTextEditor::Range range, const QString& text)
{
    return doc->replaceText(range, text);
}
