/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2012  Fredrik Persson <email>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/


#include "CXmlReader.h"

iptc_data CXmlReader::readFile(std::string file){
  iptc_data data;
  boost::property_tree::ptree pt;
  boost::property_tree::xml_parser::read_xml(file, pt);
  
  data.Artist = pt.get<std::string>("iptc.Artist");
  data.Copyright = pt.get<std::string>("iptc.Copyright");
  data.Label = pt.get<std::string>("iptc.Label");
  data.CiAdrCity = pt.get<std::string>("iptc.CityAdress");
  data.CiAdrCtry = pt.get<std::string>("iptc.Country");
  data.CiAdrEmailWork = pt.get<std::string>("iptc.Email");
  data.CiAdrExtadr = pt.get<std::string>("iptc.Street");
  data.CiAdrPcode = pt.get<std::string>("iptc.PostalCode");
  data.CiUrlWork = pt.get<std::string>("iptc.Webpage");
  return data;
}


