/*
 * File.h
 *
 *  Created on: 25 nov. 2011
 *      Author: rmeeuws
 */

#ifndef FILE_H_
#define FILE_H_

#include <fstream>
#include <string>
#include "Exception.h"

using namespace std;

namespace predictor
{

  class File
  {
  protected:
    string m_filename;
    fstream m_file;
  public:
    File(const string&) throw(Exception *);
    virtual ~File();

    const string& FileName() { return m_filename; }

    virtual void save() = 0;
    virtual void reload();
  };

} /* namespace predictor */
#endif /* FILE_H_ */
