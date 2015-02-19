/******************************************************************************      
 *      Extended Mirror: Item.cpp                                         *
 ******************************************************************************
 *      Copyright (c) 2012-2015, Manuele Finocchiaro                          *
 *      All rights reserved.                                                  *
 ******************************************************************************
 * Redistribution and use in source and binary forms, with or without         *
 * modification, are permitted provided that the following conditions         *
 * are met:                                                                   *
 *                                                                            *
 *    1. Redistributions of source code must retain the above copyright       *
 *       notice, this list of conditions and the following disclaimer.        *
 *                                                                            *
 *    2. Redistributions in binary form must reproduce the above copyright    *
 *       notice, this list of conditions and the following disclaimer in      *
 *       the documentation and/or other materials provided with the           *
 *       distribution.                                                        *
 *                                                                            *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"* 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE *
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE  *
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR        *
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF       *
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS   *
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    *
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    *
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF     *
 * THE POSSIBILITY OF SUCH DAMAGE.                                            *
 *****************************************************************************/


#include <XM/Utils/Utils.hpp>
#include <XM/xMirror.hpp>
#include <XM/Utils/Names.hpp>

using namespace std;
using namespace xm;

Item::Item(const Namespace& name_space, const string& unqualifiedName) :
        unqualifiedName_(unqualifiedName), namespace_(&name_space)
{
}

Item::Item(const string& name) :
        unqualifiedName_(name),
        namespace_(NULL)
{
}

const string& Item::getUnqualifiedName() const
{
    return unqualifiedName_;
}


string Item::getName() const
{
    if (namespace_)
        return namespace_->getName() + "::" + unqualifiedName_;
    else
        return unqualifiedName_;
}


const Namespace& Item::getNamespace() const
{
    if (namespace_)
        return *namespace_;
    else
        return Register::getSingleton();
}


Item::~Item()
{
}

