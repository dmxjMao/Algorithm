#pragma once
//
//class Window {
//public:
//	virtual void DrawLine(const Point&, const Point&);
//	//ÆäËû³éÏó
//protected:
//	WindowImp* GetWindowImp();
//	//...
//private:
//	WindowImp* _Imp;
//	//...
//};
//
//class WindowImp {
//public:
//	virtual void ImpDrawMethod() = 0;
//	//...
//};
//
//
//void IconWindow::DrawContents() {
//	WindowImp* imp = GetWindowImp();
//	imp->XXX();
//}
//
//
//WindowImp* Window::GetWindowImp() {
//	_imp = WindowSystemFactory::Instance()->MakeWindowImp();
//}
//
//
//void Window::SetContents(VisualComponent* contents);
//
//window->SetContents(
//	new BorderDecorator(
//		new ScrollDecorator(textView), 1)
//);
//
//
//class Glyph {
//public:
//	virtual void Draw(Window*, GlyphContext&);
//	//...
//};
//
//class Character : public Glyph {
//public:
//
//};
//
//
//class GlyphContext {
//public:
//	virtual void Next(int step = 1);
//	virtual void Insert(int quantity = 1);
//	//GetFont,SetFont...
//private:
//	int _index;
//	BTree* _fonts;
//};
//
//
//Image* ImageProxy::GetImage() {
//	if (_image == 0) {
//		_image = new Image(_fileName);
//	}
//	return _image;
//}