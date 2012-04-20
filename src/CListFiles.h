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

//CListFiles.h
#ifndef __CFILELIST_H__
#define __CFILELIST_H__

#include <iostream>
#include <vector>

#include <boost/filesystem.hpp>

class CListFiles {
public:
  /**
   * @brief Listar alla filtrerade filer av en viss typ.
   * @note Förlitar sig lite primitivt på filändelsen.
   * @param dir till katalog att scana
   * @param extention ändelsen som ska filtreras på.
   * @return std::vector<std::string>
   */
  std::vector<std::string>ListFiltredFiles(std::string dir, std::string extention);
};
#endif