#ifndef COIN_SOARRAY_H
#define COIN_SOARRAY_H

/**************************************************************************\
 *
 *  This file is part of the Coin 3D visualization library.
 *  Copyright (C) by Kongsberg Oil & Gas Technologies.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  ("GPL") version 2 as published by the Free Software Foundation.
 *  See the file LICENSE.GPL at the root directory of this source
 *  distribution for additional information about the GNU GPL.
 *
 *  For using Coin with software that can not be combined with the GNU
 *  GPL, and for taking advantage of the additional benefits of our
 *  support services, please contact Kongsberg Oil & Gas Technologies
 *  about acquiring a Coin Professional Edition License.
 *
 *  See http://www.coin3d.org/ for more information.
 *
 *  Kongsberg Oil & Gas Technologies, Bygdoy Alle 5, 0257 Oslo, NORWAY.
 *  http://www.sim.no/  sales@sim.no  coin-support@coin3d.org
 *
\**************************************************************************/

#include <Inventor/nodes/SoSubNode.h>
#include <Inventor/nodes/SoGroup.h>
#include <Inventor/fields/SoSFEnum.h>
#include <Inventor/fields/SoSFShort.h>
#include <Inventor/fields/SoSFVec3f.h>

class COIN_DLL_API SoArray : public SoGroup {
    typedef SoGroup inherited;

  SO_NODE_HEADER(SoArray);

public:
  static void initClass(void);
  SoArray(void);

  enum Origin {
    FIRST, CENTER, LAST
  };

  SoSFEnum origin;
  SoSFShort numElements1;
  SoSFShort numElements2;
  SoSFShort numElements3;
  SoSFVec3f separation1;
  SoSFVec3f separation2;
  SoSFVec3f separation3;

  virtual SbBool affectsState(void) const;

  virtual void doAction(SoAction * action);
  virtual void callback(SoCallbackAction * action);
  virtual void GLRender(SoGLRenderAction * action);
  virtual void pick(SoPickAction * action);
  virtual void getBoundingBox(SoGetBoundingBoxAction * action);
  virtual void handleEvent(SoHandleEventAction * action);
  virtual void getMatrix(SoGetMatrixAction * action);
  virtual void search(SoSearchAction * action);
  virtual void getPrimitiveCount(SoGetPrimitiveCountAction * action);
  virtual void audioRender(SoAudioRenderAction * action);

protected:
  virtual ~SoArray();
};

#endif // !COIN_SOARRAY_H
