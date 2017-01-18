///////////////////////////////////////////////////////////////////////////////
// ControllerGL.cpp
// ================
// Derived Controller class for OpenGL window
// It is the controller of OpenGL rendering window. It initializes DC and RC,
// when WM_CREATE called, then, start new thread for OpenGL rendering loop.
//
// When this class is constructed, it gets the pointers to model and view
// components.
//
//  AUTHOR: Song Ho Ahn (song.ahn@gamil.com)
// CREATED: 2006-07-09
// UPDATED: 2016-07-16
///////////////////////////////////////////////////////////////////////////////

#include "ControllerGL.h"
#include "Log.h"
using namespace Win;



///////////////////////////////////////////////////////////////////////////////
// default contructor
///////////////////////////////////////////////////////////////////////////////
ControllerGL::ControllerGL(ModelGL* model, ViewGL* view) : model(model), view(view),
                                                           loopFlag(false)
{
}



///////////////////////////////////////////////////////////////////////////////
// handle WM_CLOSE
///////////////////////////////////////////////////////////////////////////////
int ControllerGL::close()
{
    // wait for rendering thread is terminated
    loopFlag = false;
    glThread.join();

    ::DestroyWindow(handle);
    Win::log("OpenGL window is destroyed.");
    return 0;
}



///////////////////////////////////////////////////////////////////////////////
// handle WM_CREATE
///////////////////////////////////////////////////////////////////////////////
int ControllerGL::create()
{
    // create a OpenGL rendering context
    if(!view->createContext(handle, 32, 24, 8))
    {
        Win::log(L"[ERROR] Failed to create OpenGL rendering context from ControllerGL::create().");
        return -1;
    }

    // create a thread for OpenGL rendering
    glThread = std::thread(&ControllerGL::runThread, this);
    loopFlag = true;
    Win::log(L"Created a rendering thread for OpenGL.");

    return 0;
}



///////////////////////////////////////////////////////////////////////////////
// handle WM_PAINT
///////////////////////////////////////////////////////////////////////////////
int ControllerGL::paint()
{
    return 0;
}

///////////////////////////////////////////////////////////////////////////////
// handle WM_COMMAND
///////////////////////////////////////////////////////////////////////////////
int ControllerGL::command(int id, int cmd, LPARAM msg)
{
    return 0;
}



///////////////////////////////////////////////////////////////////////////////
// rendering thread
// initialize OpenGL states and start rendering loop
///////////////////////////////////////////////////////////////////////////////
void ControllerGL::runThread()
{
    // set the current RC in this thread
    ::wglMakeCurrent(view->getDC(), view->getRC());

    // initialize OpenGL states
    model->init();
    Win::log(L"Initialized OpenGL states.");

    // cofigure projection matrix
    RECT rect;
    ::GetClientRect(handle, &rect);
    model->resizeWindow(rect.right, rect.bottom);
    Win::log(L"Initialized OpenGL viewport and projection matrix.");

    // rendering loop
    Win::log(L"Entering OpenGL rendering thread...");
    while(loopFlag)
    {
        //std::this_thread::yield();      // yield to other processes or threads
        std::this_thread::sleep_for(std::chrono::milliseconds(1));  // yield to other processes or threads
        model->draw();
        view->swapBuffers();
    }

    // close OpenGL Rendering Context (RC)
    view->closeContext(handle);
    ::wglMakeCurrent(0, 0);             // unset RC
    Win::log(L"Closed OpenGL context.");

    Win::log(L"Exit OpenGL rendering thread.");
}



///////////////////////////////////////////////////////////////////////////////
// handle Left mouse down
///////////////////////////////////////////////////////////////////////////////
int ControllerGL::lButtonDown(WPARAM state, int x, int y)
{
    // update mouse position
    model->setMousePosition(x, y);

    if(state == MK_LBUTTON)
    {
        model->setMouseLeft(true);
    }

    return 0;
}



///////////////////////////////////////////////////////////////////////////////
// handle Left mouse up
///////////////////////////////////////////////////////////////////////////////
int ControllerGL::lButtonUp(WPARAM state, int x, int y)
{
    // update mouse position
    model->setMousePosition(x, y);

    model->setMouseLeft(false);

    return 0;
}



///////////////////////////////////////////////////////////////////////////////
// handle reft mouse down
///////////////////////////////////////////////////////////////////////////////
int ControllerGL::rButtonDown(WPARAM state, int x, int y)
{
    // update mouse position
    model->setMousePosition(x, y);

    if(state == MK_RBUTTON)
    {
        model->setMouseRight(true);
    }

    return 0;
}



///////////////////////////////////////////////////////////////////////////////
// handle reft mouse up
///////////////////////////////////////////////////////////////////////////////
int ControllerGL::rButtonUp(WPARAM state, int x, int y)
{
    // update mouse position
    model->setMousePosition(x, y);

    model->setMouseRight(false);

    return 0;
}



///////////////////////////////////////////////////////////////////////////////
// handle WM_MOUSEMOVE
///////////////////////////////////////////////////////////////////////////////
int ControllerGL::mouseMove(WPARAM state, int x, int y)
{
    if(state == MK_LBUTTON)
    {
        model->rotateCamera(x, y);
    }
    if(state == MK_RBUTTON)
    {
        model->zoomCamera(y);
    }

    return 0;
}



///////////////////////////////////////////////////////////////////////////////
// handle WM_SIZE
///////////////////////////////////////////////////////////////////////////////
int ControllerGL::size(int w, int h, WPARAM wParam)
{
    model->resizeWindow(w, h);
    Win::log(L"OpenGL window is resized: %dx%d.", w, h);
    return 0;
}
