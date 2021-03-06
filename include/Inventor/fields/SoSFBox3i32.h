#ifndef COIN_SOSFBOX3I32_H
#define COIN_SOSFBOX3I32_H

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

#include <Inventor/fields/SoSField.h>
#include <Inventor/fields/SoSubField.h>
#include <Inventor/SbBox3i32.h>

class COIN_DLL_API SoSFBox3i32 : public SoSField {
  typedef SoSField inherited;

  SO_SFIELD_HEADER(SoSFBox3i32, SbBox3i32, const SbBox3i32 &);

public:
  static void initClass(void);

  void setValue(int32_t xmin, int32_t ymin, int32_t zmin,
                int32_t xmax, int32_t ymax, int32_t zmax);
  void setValue(const SbVec3i32 & minvec, const SbVec3i32 & maxvec);
  void getValue(SbBox3i32 & box) const;

}; // SoSFBox3i32

#endif // !COIN_SOSFBOX3I32_H
