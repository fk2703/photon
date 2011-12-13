#include <vector>
#include <deque>
#include <time.h>

#include "photon.h"
#define RESOLUTION 5

#pragma comment( lib, "opengl32.lib" ) // ������ OpenGL32.lib ��� ��������
#pragma comment( lib, "glu32.lib" )    // ������ GLu32.lib ��� ��������

using namespace std;

GLWindow glwWnd(RESOLUTION);


LRESULT CALLBACK WndProc(  HWND  hWnd,      // ���������� ������� ����
	UINT  uMsg,								// ��������� ��� ����� ����
	WPARAM  wParam,							// �������������� ����������
	LPARAM  lParam)							// �������������� ����������
{
	switch (uMsg)							// �������� ��������� ��� ����
	{
	case WM_ACTIVATE:						// �������� ��������� ���������� ����
		{
			if( !HIWORD( wParam ) )			// ��������� ��������� �����������
			{
				glwWnd.active = true;				// ��������� �������
			}
			else
			{
				glwWnd.active = false;				// ��������� ������ �� �������
			}

			return 0;						// ������������ � ���� ��������� ���������
		}

	case WM_SYSCOMMAND:						// ������������� ��������� �������
		{
			switch ( wParam )				// ������������� ��������� �����
			{
			case SC_SCREENSAVE:				// �������� �� ���������� �����������?
			case SC_MONITORPOWER:			// �������� �� ������� ������� � ����� ���������� �������?
				return 0;					// ������������� ���
			}
			break;							// �����
		}

	case WM_CLOSE:							// �� �������� ��������� � ��������?
		{
			PostQuitMessage( 0 );			// ��������� ��������� � ������
			return 0;						// ��������� �����
		}

	case WM_KEYDOWN:						// ���� �� ������ ������?
		{
			glwWnd.keys[wParam] = true;			// ���� ���, �� ����������� ���� ������ true
			return 0;						// ������������
		}

	case WM_KEYUP:							// ���� �� �������� �������?
		{
			glwWnd.keys[wParam] = false;			//  ���� ���, �� ����������� ���� ������ false
			return 0;						// ������������
		}

	case WM_SIZE:							// �������� ������� OpenGL ����
		{
			glwWnd.ReSizeGLScene( LOWORD(lParam), HIWORD(lParam) );	// ������� �����=Width, ������� �����=Height
			return 0;						// ������������
		}
	}

	// ���������� ��� �������������� ��������� DefWindowProc
	return DefWindowProc( hWnd, uMsg, wParam, lParam );
}

int WINAPI WinMain(  HINSTANCE  hInstance,  // ���������� ����������
	HINSTANCE  hPrevInstance,				// ���������� ������������� ����������
	LPSTR    lpCmdLine,						// ��������� ��������� ������
	int    nCmdShow )						// ��������� ����������� ����
{
	MSG  msg;								// ��������� ��� �������� ��������� Windows
	BOOL  done = false;						// ���������� ���������� ��� ������ �� �����


	glwWnd.fullscreen = false;				// ������� �����


	// ������� ���� OpenGL ����
	if( !glwWnd.CreateGLWindow("Photon", 400, 300, 32) )
	{
		return 0;							// �����, ���� ���� �� ����� ���� �������
	}
	srand (time(NULL));
	Viewport vpViewport(glwWnd.Resolution, 100);
	ImageSensor &isSensor_a = vpViewport.oWorld.isSensor;
	
	vpViewport.sSuns.push_front(Sun(5, 5, 0));

	while( !done )							// ���� ������������, ���� done �� ����� true
	{
		if( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) )	// ���� �� � ������� �����-������ ���������?
		{
			if( msg.message == WM_QUIT )    // �� ������� ��������� � ������?
			{
				done = true;				// ���� ���, done=true
			}

			else							// ���� ���, ������������ ���������
			{
				TranslateMessage( &msg );   // ��������� ���������
				DispatchMessage( &msg );	// �������� ���������
			}
		}
		else								// ���� ��� ���������
		{
			// ������������� �����.
			if( glwWnd.active )					// ������� �� ���������?
			{
				if(glwWnd.keys[VK_ESCAPE])			// ���� �� ������ ������� ESC?
				{
					done = true;			// ESC ������� �� �������� ���������� ���������
				}
				else						// �� ����� ��� ������, ������� �����.
				{

					//��������� ������� ���� ���
					for (int i = 0; i < vpViewport.Resolution; i++)
					for (int j = 0; j < vpViewport.Resolution; j++)
					{
						isSensor_a[i*vpViewport.Resolution + j] = (float)((int) rand()%100)/100.0;
					}

					vpViewport.OneStep();
					glwWnd.DrawGLScene(isSensor_a);			// ������ �����
					SwapBuffers( glwWnd.hDC );		// ������ ����� (������� �����������)
				}
			}
		}
	}

	glwWnd.KillGLWindow();						// ��������� ����
	return ( msg.wParam );					// ������� �� ���������
}