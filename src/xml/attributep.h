#ifndef COIN_XMLATTRIBUTEP_H
#define COIN_XMLATTRIBUTEP_H

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
#error This is an internal header file.
#endif // !COIN_INTERNAL

#include <Inventor/C/XML/types.h>

size_t cc_xml_attr_calculate_size(const cc_xml_attr * attr);
size_t cc_xml_attr_write_to_buffer(const cc_xml_attr * attr, char * buffer, size_t bufsize);

#endif // !COIN_XMLATTRIBUTEP_H
