#include <gtest/gtest.h>

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <fstream>

#include <boost/filesystem.hpp>

#include <exiv2/image.hpp>
#include <exiv2/exif.hpp>

#include "../src/CListFiles.h"
#include "../src/iptc_struct.h"
#include "../src/CExifWriter.h"
#include "../src/CXmlReader.h"

TEST(ListFiles, ls){
  boost::filesystem::path path;
  path /= boost::filesystem::current_path();
  path /= "test_data";
  
  CListFiles List;
  std::vector<std::string> testlist = List.ListFiltredFiles(path.string(), ".foo");
  
  EXPECT_EQ(testlist.size(), 2);
}

TEST(WriteData, write){  
  boost::filesystem::path srcpath;
  srcpath /= boost::filesystem::current_path();
  srcpath /= "test_data/testimg.jpg";
  
  boost::filesystem::path destpath;
  destpath /= boost::filesystem::current_path();
  destpath /= "test_data/img1.jpg";
  
  iptc_data iptc;
  iptc.Artist = "Fredrik Persson";
  iptc.Copyright = "Copyright, Fredrik Persson, 2012. All rights reserved.";
  iptc.CiAdrCity = "Footown";
  iptc.CiAdrExtadr = "Barstreet";
  iptc.CiAdrPcode = "111 11";
  iptc.CiAdrCtry = "Sweden";
  iptc.CiAdrEmailWork = "fredrik@foobar.com";
  iptc.CiUrlWork = "http://example.com/photos";
  iptc.Label = "Foo.";
  
  boost::filesystem::copy_file(srcpath, destpath,  boost::filesystem::copy_option::overwrite_if_exists);
  
  CExifWriter writer;
  writer.WriteData(destpath.string(), iptc);
  
  //hämta testresultat....
  Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(destpath.string());
  image->readMetadata();
  Exiv2::ExifData exifData = image->exifData();
  Exiv2::XmpData xmpData = image->xmpData();
    
  EXPECT_EQ(iptc.Artist, exifData["Exif.Image.Artist"].toString());
  EXPECT_EQ(iptc.Copyright, exifData["Exif.Image.Copyright"].toString());
  
  EXPECT_EQ(iptc.CiAdrCity, xmpData["Xmp.iptc.CiAdrCity"].toString());
  EXPECT_EQ(iptc.CiAdrCtry, xmpData["Xmp.iptc.CiAdrCtry"].toString());
  EXPECT_EQ(iptc.CiAdrEmailWork, xmpData["Xmp.iptc.CiAdrEmailWork"].toString());
  EXPECT_EQ(iptc.CiAdrExtadr, xmpData["Xmp.iptc.CiAdrExtadr"].toString());
  EXPECT_EQ(iptc.CiAdrPcode, xmpData["Xmp.iptc.CiAdrPcode"].toString());
  EXPECT_EQ(iptc.CiUrlWork, xmpData["Xmp.iptc.CiUrlWork"].toString());
  
  EXPECT_EQ(iptc.Label, xmpData["Xmp.xmp.Label"].toString());
  
  boost::filesystem::remove(destpath);
}

TEST(ReadXml, read){
  boost::filesystem::path path;
  path /= boost::filesystem::current_path();
  path /= "test_data/test.xml";
  
  CXmlReader reader;  
  iptc_data data = reader.readFile(path.string());
  
  EXPECT_EQ("Fredrik Persson", data.Artist);
  EXPECT_EQ("Copyright, Fredrik Persson, 2012. All rights reserved." ,data.Copyright);
  
  EXPECT_EQ("Footown",data.CiAdrCity);
  EXPECT_EQ("Sweden", data.CiAdrCtry);
  EXPECT_EQ("fredrik.persson@foobar.com", data.CiAdrEmailWork);
  EXPECT_EQ("Barstreet", data.CiAdrExtadr);
  EXPECT_EQ("111 11", data.CiAdrPcode);
  EXPECT_EQ("http://example.com/photos", data.CiUrlWork);
  
  EXPECT_EQ("Min bild.", data.Label);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}
