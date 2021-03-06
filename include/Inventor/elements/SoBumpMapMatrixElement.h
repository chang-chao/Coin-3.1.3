#ifndef COIN_SOBUMPMAPMATRIXELEMENT_H
#define COIN_SOBUMPMAPMATRIXELEMENT_H

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

#include <Inventor/elements/SoAccumulatedElement.h>
#include <Inventor/SbMatrix.h>

class COIN_DLL_API SoBumpMapMatrixElement : public SoAccumulatedElement {
  typedef SoAccumulatedElement inherited;

  SO_ELEMENT_HEADER(SoBumpMapMatrixElement);
public:
  static void initClass(void);
protected:
  virtual ~SoBumpMapMatrixElement();

public:
  virtual void init(SoState * state);
  virtual void push(SoState * state);
  static void makeIdentity(SoState * const state, SoNode * const node);

  static void set(SoState * const state, SoNode * const node,
                  const SbMatrix & matrix);
  static void mult(SoState * const state, SoNode * const node,
                   const SbMatrix & matrix);

  static void translateBy(SoState * const state, SoNode * const node,
                           const SbVec3f & translation);
  static void rotateBy(SoState * const state, SoNode * const node,
                        const SbRotation & rotation);
  static void scaleBy(SoState * const state, SoNode * const node,
                      const SbVec3f & scaleFactor);

  static const SbMatrix & get(SoState * const state);

protected:
  virtual void makeEltIdentity(void);
  virtual void setElt(const SbMatrix & matrix);
  virtual void multElt(const SbMatrix & matrix);
  virtual void translateEltBy(const SbVec3f & translation);
  virtual void rotateEltBy(const SbRotation & rotation);
  virtual void scaleEltBy(const SbVec3f & scaleFactor);
  virtual const SbMatrix & getElt(void) const;
  
  SbMatrix bumpMapMatrix;
};

#endif // !COIN_SOBUMPMAPMATRIXELEMENT_H
