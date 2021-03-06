#ifndef CC_FIFOP_H
#define CC_FIFOP_H

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

#ifndef COIN_INTERNAL
#error this is a private header file
#endif /* !COIN_INTERNAL */

#include <Inventor/C/threads/common.h>

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif /* HAVE_CONFIG_H */

#include "threads/mutexp.h"
#include "threads/condvarp.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* ********************************************************************** */

typedef struct cc_fifo_item cc_fifo_item;

struct cc_fifo_item {
  cc_fifo_item * next;
  void *         item;
  uint32_t       type;
};

struct cc_fifo {
  cc_mutex       access;

  cc_fifo_item * head;
  cc_fifo_item * tail;
  cc_fifo_item * free;

  unsigned int   elements;

  cc_condvar     sleep;
};

/* ********************************************************************** */

void cc_fifo_struct_init(cc_fifo * fifo);
void cc_fifo_struct_clean(cc_fifo * fifo);

/* ********************************************************************** */

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* ! CC_FIFOP_H */
