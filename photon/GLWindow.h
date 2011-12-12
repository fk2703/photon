#pragma once
#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <vector>

class GLWindow
{
public:
	GLWindow(int iResolution);
	~GLWindow(void);

	void KillGLWindow(void);
	int InitGL(void);
	void ReSizeGLScene( GLsizei width, GLsizei height );
	bool CreateGLWindow( LPCSTR title, int width, int height, int bits);
	int DrawGLScene(std::vector<float> Matrix);

	HGLRC  hRC;						// Постоянный контекст рендеринга
	HDC  hDC;						// Приватный контекст устройства GDI
	HWND  hWnd;						// Здесь будет хранится дескриптор окна
	HINSTANCE  hInstance;           // Здесь будет хранится дескриптор приложения

	bool  keys[256];				// Массив, используемый для операций с клавиатурой
	bool  active;					// Флаг активности окна, установленный в true по умолчанию
	bool  fullscreen;				// Флаг режима окна, установленный в полноэкранный по умолчанию

private:
	float fMulCoeffitient;
	int Resolution;
};
