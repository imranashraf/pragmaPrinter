/*
 * File.cpp
 *
 *  Created on: 25 nov. 2011
 *      Author: rmeeuws
 */

#include "File.h"
#include <iostream>

namespace predictor
{

    File::File(const string& filename) throw(Exception *)
        :m_file(filename.c_str())
    {
        m_filename = filename;
        if(!m_file.good())
		{
			cout<<"\n Going to throw exception from File constructor "<<endl;
            //throw new Exception("Cannot read file " + filename,__FILE__,__LINE__);
		}
    }

    File::~File()
    {
        m_file.close();
    }
    void File::reload()
    {
        m_file.close();
        m_file.open(m_filename.c_str());
        if(!m_file.good())
		{
			cout<<"\n Going to throw exception from File reload "<<endl;
            throw new Exception("Cannot read file " + m_filename,__FILE__,__LINE__);
		}
    }
} /* namespace predictor */
