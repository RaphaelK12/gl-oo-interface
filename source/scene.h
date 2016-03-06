/******************************************+
*                                          *
*  CSCI420 - Computer Graphics USC         *
*  Author: Rodrigo Castiel                 *
*                                          *
+*******************************************/

#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "basic_obj_library.h"
#include "camera.h"
#include "light.h"

class Scene
{
public:
  Scene() { }

  virtual void Init(BasicPipelineProgram* pipelineProgram, GLuint programHandle);
  virtual void Clean();

  virtual void Render();
  virtual void Animate();

  virtual void ReshapeScreen(int w, int h);
  bool IsInitialized() const { return mInitialized; }
  
  virtual void OnMouseLeftClick(int x, int y, int w, int h)   { }
  virtual void OnMouseRightClick(int x, int y, int w, int h)  { }

  virtual void ChangeCamera();
  virtual Camera* GetCurrentCamera() { return mCameras[mCurrentCamera]; };

  virtual void AddCamera(Camera::CameraType type);
  virtual void AddCamera(Camera* camera);
  virtual void AddObject(SceneObject* object);

  virtual void Load() {  }

  void SetPipelineProgramParam(BasicPipelineProgram *pipelineProgram, GLuint programHandle);

  virtual ~Scene() { Scene::Clean(); }

protected:
  BasicPipelineProgram* mPipelineProgram { nullptr };
  GLuint mProgramHandle { 0 };
  bool mInitialized { false };

  std::vector<Light*> mLights;
  std::vector<Camera*> mCameras;
  std::vector<SceneObject*> mObjects;
  int mCurrentCamera { 0 };

  std::vector<Mesh*> meshes;
  std::vector<Texture*> mTextures;
  std::vector<Material*> mMaterials;

}; // Scene.

inline
void Scene::SetPipelineProgramParam(BasicPipelineProgram *pipelineProgram, 
  GLuint programHandle) 
{ 
  mProgramHandle   = programHandle; 
  mPipelineProgram = pipelineProgram;
}


#endif