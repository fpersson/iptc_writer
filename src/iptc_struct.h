/**  This file is part of iptc_writer
 * 
 *  Copyright (C) 2012 Fredrik Persson <fpersson.se@gmail.com>
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public License
 *  along with this library; see the file COPYING.LIB.  If not, write to
 *  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *  Boston, MA 02110-1301, USA.
 */

#ifndef __IPTC_STRUCT_H__
#define __IPTC_STRUCT_H__

#include <string>

struct iptc_data{
  /** @brief Uphovsmann, i form av kameranägare, fotograf och eller redigerare */
  std::string Artist; //Exif.Image.*
  /** @brief copyright "Copyright, Fredrik Persson, 2012. All rights reserved." */
  std::string Copyright; //Exif.Image.*
  /** @brief Kontakt info - stad */
  std::string CiAdrCity; //Xmp.iptc.*
  /** @brief Kontakt info - land */
  std::string CiAdrCtry; //Xmp.iptc.*
  /** @brief Kontakt info - gata */
  std::string CiAdrExtadr; //Xmp.iptc.*
  /** @brief Kontakt info - postnummer */
  std::string CiAdrPcode; //Xmp.iptc.*
  /** @brief Kontakt info - email */
  std::string CiAdrEmailWork; //Xmp.iptc.*
  /** @brief Kontakt info - webpage */
  std::string CiUrlWork; //Xmp.iptc.*
  /** @brief ettiket som ord eller kort beskrivande fras */
  std::string Label; //Xmp.xmp.*
};

#endif