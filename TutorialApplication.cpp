/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.cpp
-----------------------------------------------------------------------------

This source file is part of the
   ___                 __    __ _ _    _
  /___\__ _ _ __ ___  / / /\ \ (_) | _(_)
 //  // _` | '__/ _ \ \ \/  \/ / | |/ / |
/ \_// (_| | | |  __/  \  /\  /| |   <| |
\___/ \__, |_|  \___|   \/  \/ |_|_|\_\_|
      |___/
      Tutorial Framework
      http://www.ogre3d.org/tikiwiki/
-----------------------------------------------------------------------------
*/
#include "TutorialApplication.h"

//-------------------------------------------------------------------------------------
TutorialApplication::TutorialApplication(void)
{
}
//-------------------------------------------------------------------------------------
TutorialApplication::~TutorialApplication(void)
{
}

//-------------------------------------------------------------------------------------
void TutorialApplication::createScene(void)
{
    // Set the default lighting.
    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5f, 0.5f, 0.5f));

    // Create entity and scene node
    mEntity = mSceneMgr->createEntity("Robot", "robot.mesh");
    mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("RobotNode",
        Ogre::Vector3(0.0f, 0.0f, 25.0f));
    mNode->attachObject(mEntity);

    // Create the walking list
    mWalkList.push_back(Ogre::Vector3(550.0f,  0.0f,  50.0f ));
    mWalkList.push_back(Ogre::Vector3(-100.0f,  0.0f, -200.0f));

    // Create objects so we can see movement
    Ogre::Entity *ent;
    Ogre::SceneNode *node;

    ent = mSceneMgr->createEntity("Knot1", "knot.mesh");
    node = mSceneMgr->getRootSceneNode()->createChildSceneNode("Knot1Node",
        Ogre::Vector3(0.0f, -10.0f,  25.0f));
    node->attachObject(ent);
    node->setScale(0.1f, 0.1f, 0.1f);

    ent = mSceneMgr->createEntity("Knot2", "knot.mesh");
    node = mSceneMgr->getRootSceneNode()->createChildSceneNode("Knot2Node",
        Ogre::Vector3(550.0f, -10.0f,  50.0f));
    node->attachObject(ent);
    node->setScale(0.1f, 0.1f, 0.1f);

    ent = mSceneMgr->createEntity("Knot3", "knot.mesh");
    node = mSceneMgr->getRootSceneNode()->createChildSceneNode("Knot3Node",
        Ogre::Vector3(-100.0f, -10.0f,-200.0f));
    node->attachObject(ent);
    node->setScale(0.1f, 0.1f, 0.1f);

    // Set the camera to look at our handiwork
    mCamera->setPosition(90.0f, 280.0f, 535.0f);
    mCamera->pitch(Ogre::Degree(-30.0f));
    mCamera->yaw(Ogre::Degree(-15.0f));
}

//-------------------------------------------------------------------------------------
void TutorialApplication::createFrameListener(void){
	BaseApplication::createFrameListener();
}

//-------------------------------------------------------------------------------------
bool TutorialApplication::nextLocation(void){
	return true;
}

//-------------------------------------------------------------------------------------
bool TutorialApplication::frameRenderingQueued(const Ogre::FrameEvent &evt){
	return BaseApplication::frameRenderingQueued(evt);
}

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
    int main(int argc, char *argv[])
#endif
    {
        // Create application object
        TutorialApplication app;

        try {
            app.go();
        } catch( Ogre::Exception& e ) {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
            MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
            std::cerr << "An exception has occured: " <<
                e.getFullDescription().c_str() << std::endl;
#endif
        }

        return 0;
    }

#ifdef __cplusplus
}
#endif
