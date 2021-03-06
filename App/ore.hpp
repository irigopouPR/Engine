/*
 Copyright (C) 2016 Quaternion Risk Management Ltd
 All rights reserved.

 This file is part of ORE, a free-software/open-source library
 for transparent pricing and risk analysis - http://opensourcerisk.org

 ORE is free software: you can redistribute it and/or modify it
 under the terms of the Modified BSD License.  You should have received a
 copy of the license along with this program.
 The license is also available online at <http://opensourcerisk.org>

 This program is distributed on the basis that it will form a useful
 contribution to risk analytics and model standardisation, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 FITNESS FOR A PARTICULAR PURPOSE. See the license for more details.
*/

/*! \file App/ore.hpp
    \brief Open Risk Engine setup and analytics choice
    \ingroup
*/

#pragma once

#include <vector>
#include <map>

#include <ored/utilities/xmlutils.hpp>

using namespace std;
using namespace ore::data;

class Parameters : public XMLSerializable {
public:
    Parameters() {}

    void clear();
    void fromFile(const string&);
    virtual void fromXML(XMLNode* node);
    virtual XMLNode* toXML(XMLDocument& doc);

    bool hasGroup(const string& groupName) const;
    bool has(const string& groupName, const string& paramName) const;
    string get(const string& groupName, const string& paramName) const;

    void log();

private:
    map<string, map<string, string>> data_;
};
