#include <windows.h>            // ������������ ����� ��� Windows
#include <gl\gl.h>				// ������������ ����� ��� ���������� OpenGL32
#include <gl\glu.h>				// ������������ ����� ��� ���������� GLu32
//#include <gl\glaux.h>			// ������������ ����� ��� ���������� GLaux
#include <vector>
#include <deque>
#include <time.h>

#include "GLWindow.h"
#include "photon.h"

#pragma comment( lib, "opengl32.lib" ) // ������ OpenGL32.lib ��� ��������
#pragma comment( lib, "glu32.lib" )    // ������ GLu32.lib ��� ��������

using namespace std;

GLWindow glwWnd;


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
	Viewport VPort(100, 100);
	/*
	int num_photons;
	sun *l1 = NULL;
	deque<photon> photons;
	deque<photon>& photons_ref = photons;

	l1 = new_sun(6.0, 5.0, 5.0);
	*/

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

					
					for (int i = 0; i < VPort.Resolution; i++)
					for (int j = 0; j < VPort.Resolution; j++)
					{
						(*VPort.Matrix)[i*VPort.Resolution + j] = (float)rand()/100;
					}
					/*
					
					for (int i = 0; i < STEPS_PER_FRAME; i++)
					{
						shine(l1, photons_ref);
						num_photons = step(photons_ref, MATRIX);
					}
				*/
					VPort.DrawGLScene();			// ������ �����
					SwapBuffers( glwWnd.hDC );		// ������ ����� (������� �����������)
				}
			}


		}
	}

	glwWnd.KillGLWindow();						// ��������� ����
	return ( msg.wParam );					// ������� �� ���������
}