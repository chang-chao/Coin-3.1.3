#ifndef COIN_SOROTATECYLINDRICALDRAGGER_H
#define COIN_SOROTATECYLINDRICALDRAGGER_H

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

#include <Inventor/draggers/SoDragger.h>
#include <Inventor/tools/SbLazyPimplPtr.h>
#include <Inventor/fields/SoSFRotation.h>

class SoSensor;
class SoFieldSensor;
class SbCylinderProjector;
class SoRotateCylindricalDraggerP;

class COIN_DLL_API SoRotateCylindricalDragger : public SoDragger {
  typedef SoDragger inherited;

  SO_KIT_HEADER(SoRotateCylindricalDragger);
  SO_KIT_CATALOG_ENTRY_HEADER(feedback);
  SO_KIT_CATALOG_ENTRY_HEADER(feedbackActive);
  SO_KIT_CATALOG_ENTRY_HEADER(feedbackSwitch);
  SO_KIT_CATALOG_ENTRY_HEADER(rotator);
  SO_KIT_CATALOG_ENTRY_HEADER(rotatorActive);
  SO_KIT_CATALOG_ENTRY_HEADER(rotatorSwitch);

public:
  static void initClass(void);
  SoRotateCylindricalDragger(void);

  SoSFRotation rotation;

  void setProjector(SbCylinderProjector * p);
  const SbCylinderProjector * getProjector(void) const;

protected:
  virtual ~SoRotateCylindricalDragger(void);
  virtual SbBool setUpConnections(SbBool onoff, SbBool doitalways = FALSE);

  virtual void copyContents(const SoFieldContainer * fromfc,
                            SbBool copyconnections);

  static void startCB(void * f, SoDragger * d);
  static void motionCB(void * f, SoDragger * d);
  static void doneCB(void * f, SoDragger * d);
  static void fieldSensorCB(void * f, SoSensor * s);
  static void valueChangedCB(void * f, SoDragger * d);

  void dragStart(void);
  void drag(void);
  void dragFinish(void);

  SoFieldSensor * fieldSensor;
  SbCylinderProjector * cylinderProj;
  SbBool userProj;

private:
  SbLazyPimplPtr<SoRotateCylindricalDraggerP> pimpl;

  // NOT IMPLEMENTED:
  SoRotateCylindricalDragger(const SoRotateCylindricalDragger & rhs);
  SoRotateCylindricalDragger & operator = (const SoRotateCylindricalDragger & rhs);
}; // SoRotateCylindricalDragger

#endif // !COIN_SOROTATECYLINDRICALDRAGGER_H
