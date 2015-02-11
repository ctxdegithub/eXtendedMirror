
/******************************************************************************      
 *      Extended Mirror: BindGetNSetProperty.hpp                              *
 ******************************************************************************
 *      Copyright (c) 2012-2014, Manuele Finocchiaro                          *
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

/* WARNING: This file has been autogenerated. Do not modify it directly! */

#ifndef XM_BINDGETNSETPROPERTY_HPP
#define	XM_BINDGETNSETPROPERTY_HPP


#define XM_GET_N_SET_EXTRA_PARAM_MAX 3


namespace xm{



template
<
    class ClassT,
    typename RetT
>
Property& bindProperty(
    const std::string& name,
    RetT (ClassT::*getter)
    ( 
    )
)
{   
    // ensure that the type is registered
    registerType<RetT>();
    
    // setter points to NULL
    void (ClassT::*setter)(Empty) =
        static_cast<void(ClassT::*)(Empty)>(NULL);
    
    // build the Property
    Property* xmProperty =
        new PropertyGetterNSetter_0_ExtrParams
        <
            ClassT,
            RetT,
            Empty
        >
        (
            name,
            getter,
            false,
            setter
        );
    const_cast<Class&>(getClass<ClassT>()).addMember(*xmProperty);
    return *xmProperty;
}



template
<
    class ClassT,
    typename RetT
>
Property& bindProperty(
    const std::string& name,
    RetT (ClassT::*getter)
    ( 
    ) const
)
{   
    // ensure that the type is registered
    registerType<RetT>();
    
    // remove constness from the getter method
    RetT (ClassT::*getter_nc)() =
        reinterpret_cast
        <
            RetT (ClassT::*)
            (
            )
        >(getter);
        
    // setter points to NULL
    void (ClassT::*setter)(Empty) =
        static_cast<void(ClassT::*)(Empty)>(NULL);
    
    // build the Property
    Property* xmProperty =
        new PropertyGetterNSetter_0_ExtrParams
        <
            ClassT,
            RetT,
            Empty
        >
        (
            name,
            getter_nc,
            true,
            setter
        );
    const_cast<Class&>(getClass<ClassT>()).addMember(*xmProperty);
    return *xmProperty;
}



template
<
    class ClassT,
    typename RetT,
    typename ParamT
>
Property& bindProperty(
    const std::string& name,
    RetT (ClassT::*getter)
    ( 
    ),
    void (ClassT::*setter)
    (
        ParamT
    )
)
{   
    // ensure that the type is registered
    registerType<RetT>();
    
    
    // build the Property
    Property* xmProperty =
        new PropertyGetterNSetter_0_ExtrParams
        <
            ClassT,
            RetT,
            ParamT
        >
        (
            name,
            getter,
            false,
            setter
        );
    const_cast<Class&>(getClass<ClassT>()).addMember(*xmProperty);
    return *xmProperty;
}



template
<
    class ClassT,
    typename RetT,
    typename ParamT
>
Property& bindProperty(
    const std::string& name,
    RetT (ClassT::*getter)
    ( 
    ) const,
    void (ClassT::*setter)
    (
        ParamT
    )
)
{   
    // ensure that the type is registered
    registerType<RetT>();
    
    // remove constness from the getter method
    RetT (ClassT::*getter_nc)() =
        reinterpret_cast
        <
            RetT (ClassT::*)
            (
            )
        >(getter);
        
    
    // build the Property
    Property* xmProperty =
        new PropertyGetterNSetter_0_ExtrParams
        <
            ClassT,
            RetT,
            ParamT
        >
        (
            name,
            getter_nc,
            true,
            setter
        );
    const_cast<Class&>(getClass<ClassT>()).addMember(*xmProperty);
    return *xmProperty;
}



template
<
    class ClassT,
    typename RetT,
    typename ExtrParamT0
>
Property& bindProperty(
    const std::string& name,
    RetT (ClassT::*getter)
    ( 
        ExtrParamT0
    ),
    ExtrParamT0 extrArg0
)
{   
    // ensure that the type is registered
    registerType<RetT>();
    
    // setter points to NULL
    void (ClassT::*setter)(Empty) =
        static_cast<void(ClassT::*)(Empty)>(NULL);
    
    // build the Property
    Property* xmProperty =
        new PropertyGetterNSetter_1_ExtrParams
        <
            ClassT,
            RetT,
            Empty,
            ExtrParamT0
        >
        (
            name,
            getter,
            false,
            setter,
            extrArg0
        );
    const_cast<Class&>(getClass<ClassT>()).addMember(*xmProperty);
    return *xmProperty;
}



template
<
    class ClassT,
    typename RetT,
    typename ExtrParamT0
>
Property& bindProperty(
    const std::string& name,
    RetT (ClassT::*getter)
    ( 
        ExtrParamT0
    ) const,
    ExtrParamT0 extrArg0
)
{   
    // ensure that the type is registered
    registerType<RetT>();
    
    // remove constness from the getter method
    RetT (ClassT::*getter_nc)() =
        reinterpret_cast
        <
            RetT (ClassT::*)
            (
                ExtrParamT0
            )
        >(getter);
        
    // setter points to NULL
    void (ClassT::*setter)(Empty) =
        static_cast<void(ClassT::*)(Empty)>(NULL);
    
    // build the Property
    Property* xmProperty =
        new PropertyGetterNSetter_1_ExtrParams
        <
            ClassT,
            RetT,
            Empty,
            ExtrParamT0
        >
        (
            name,
            getter_nc,
            true,
            setter,
            extrArg0
        );
    const_cast<Class&>(getClass<ClassT>()).addMember(*xmProperty);
    return *xmProperty;
}



template
<
    class ClassT,
    typename RetT,
    typename ParamT,
    typename ExtrParamT0
>
Property& bindProperty(
    const std::string& name,
    RetT (ClassT::*getter)
    ( 
        ExtrParamT0
    ),
    void (ClassT::*setter)
    (
        ParamT,
        ExtrParamT0
    ),
    ExtrParamT0 extrArg0
)
{   
    // ensure that the type is registered
    registerType<RetT>();
    
    
    // build the Property
    Property* xmProperty =
        new PropertyGetterNSetter_1_ExtrParams
        <
            ClassT,
            RetT,
            ParamT,
            ExtrParamT0
        >
        (
            name,
            getter,
            false,
            setter,
            extrArg0
        );
    const_cast<Class&>(getClass<ClassT>()).addMember(*xmProperty);
    return *xmProperty;
}



template
<
    class ClassT,
    typename RetT,
    typename ParamT,
    typename ExtrParamT0
>
Property& bindProperty(
    const std::string& name,
    RetT (ClassT::*getter)
    ( 
        ExtrParamT0
    ) const,
    void (ClassT::*setter)
    (
        ParamT,
        ExtrParamT0
    ),
    ExtrParamT0 extrArg0
)
{   
    // ensure that the type is registered
    registerType<RetT>();
    
    // remove constness from the getter method
    RetT (ClassT::*getter_nc)() =
        reinterpret_cast
        <
            RetT (ClassT::*)
            (
                ExtrParamT0
            )
        >(getter);
        
    
    // build the Property
    Property* xmProperty =
        new PropertyGetterNSetter_1_ExtrParams
        <
            ClassT,
            RetT,
            ParamT,
            ExtrParamT0
        >
        (
            name,
            getter_nc,
            true,
            setter,
            extrArg0
        );
    const_cast<Class&>(getClass<ClassT>()).addMember(*xmProperty);
    return *xmProperty;
}



template
<
    class ClassT,
    typename RetT,
    typename ExtrParamT0,
    typename ExtrParamT1
>
Property& bindProperty(
    const std::string& name,
    RetT (ClassT::*getter)
    ( 
        ExtrParamT0,
        ExtrParamT1
    ),
    ExtrParamT0 extrArg0,
    ExtrParamT1 extrArg1
)
{   
    // ensure that the type is registered
    registerType<RetT>();
    
    // setter points to NULL
    void (ClassT::*setter)(Empty) =
        static_cast<void(ClassT::*)(Empty)>(NULL);
    
    // build the Property
    Property* xmProperty =
        new PropertyGetterNSetter_2_ExtrParams
        <
            ClassT,
            RetT,
            Empty,
            ExtrParamT0,
            ExtrParamT1
        >
        (
            name,
            getter,
            false,
            setter,
            extrArg0,
            extrArg1
        );
    const_cast<Class&>(getClass<ClassT>()).addMember(*xmProperty);
    return *xmProperty;
}



template
<
    class ClassT,
    typename RetT,
    typename ExtrParamT0,
    typename ExtrParamT1
>
Property& bindProperty(
    const std::string& name,
    RetT (ClassT::*getter)
    ( 
        ExtrParamT0,
        ExtrParamT1
    ) const,
    ExtrParamT0 extrArg0,
    ExtrParamT1 extrArg1
)
{   
    // ensure that the type is registered
    registerType<RetT>();
    
    // remove constness from the getter method
    RetT (ClassT::*getter_nc)() =
        reinterpret_cast
        <
            RetT (ClassT::*)
            (
                ExtrParamT0,
                ExtrParamT1
            )
        >(getter);
        
    // setter points to NULL
    void (ClassT::*setter)(Empty) =
        static_cast<void(ClassT::*)(Empty)>(NULL);
    
    // build the Property
    Property* xmProperty =
        new PropertyGetterNSetter_2_ExtrParams
        <
            ClassT,
            RetT,
            Empty,
            ExtrParamT0,
            ExtrParamT1
        >
        (
            name,
            getter_nc,
            true,
            setter,
            extrArg0,
            extrArg1
        );
    const_cast<Class&>(getClass<ClassT>()).addMember(*xmProperty);
    return *xmProperty;
}



template
<
    class ClassT,
    typename RetT,
    typename ParamT,
    typename ExtrParamT0,
    typename ExtrParamT1
>
Property& bindProperty(
    const std::string& name,
    RetT (ClassT::*getter)
    ( 
        ExtrParamT0,
        ExtrParamT1
    ),
    void (ClassT::*setter)
    (
        ParamT,
        ExtrParamT0,
        ExtrParamT1
    ),
    ExtrParamT0 extrArg0,
    ExtrParamT1 extrArg1
)
{   
    // ensure that the type is registered
    registerType<RetT>();
    
    
    // build the Property
    Property* xmProperty =
        new PropertyGetterNSetter_2_ExtrParams
        <
            ClassT,
            RetT,
            ParamT,
            ExtrParamT0,
            ExtrParamT1
        >
        (
            name,
            getter,
            false,
            setter,
            extrArg0,
            extrArg1
        );
    const_cast<Class&>(getClass<ClassT>()).addMember(*xmProperty);
    return *xmProperty;
}



template
<
    class ClassT,
    typename RetT,
    typename ParamT,
    typename ExtrParamT0,
    typename ExtrParamT1
>
Property& bindProperty(
    const std::string& name,
    RetT (ClassT::*getter)
    ( 
        ExtrParamT0,
        ExtrParamT1
    ) const,
    void (ClassT::*setter)
    (
        ParamT,
        ExtrParamT0,
        ExtrParamT1
    ),
    ExtrParamT0 extrArg0,
    ExtrParamT1 extrArg1
)
{   
    // ensure that the type is registered
    registerType<RetT>();
    
    // remove constness from the getter method
    RetT (ClassT::*getter_nc)() =
        reinterpret_cast
        <
            RetT (ClassT::*)
            (
                ExtrParamT0,
                ExtrParamT1
            )
        >(getter);
        
    
    // build the Property
    Property* xmProperty =
        new PropertyGetterNSetter_2_ExtrParams
        <
            ClassT,
            RetT,
            ParamT,
            ExtrParamT0,
            ExtrParamT1
        >
        (
            name,
            getter_nc,
            true,
            setter,
            extrArg0,
            extrArg1
        );
    const_cast<Class&>(getClass<ClassT>()).addMember(*xmProperty);
    return *xmProperty;
}



template
<
    class ClassT,
    typename RetT,
    typename ExtrParamT0,
    typename ExtrParamT1,
    typename ExtrParamT2
>
Property& bindProperty(
    const std::string& name,
    RetT (ClassT::*getter)
    ( 
        ExtrParamT0,
        ExtrParamT1,
        ExtrParamT2
    ),
    ExtrParamT0 extrArg0,
    ExtrParamT1 extrArg1,
    ExtrParamT2 extrArg2
)
{   
    // ensure that the type is registered
    registerType<RetT>();
    
    // setter points to NULL
    void (ClassT::*setter)(Empty) =
        static_cast<void(ClassT::*)(Empty)>(NULL);
    
    // build the Property
    Property* xmProperty =
        new PropertyGetterNSetter_3_ExtrParams
        <
            ClassT,
            RetT,
            Empty,
            ExtrParamT0,
            ExtrParamT1,
            ExtrParamT2
        >
        (
            name,
            getter,
            false,
            setter,
            extrArg0,
            extrArg1,
            extrArg2
        );
    const_cast<Class&>(getClass<ClassT>()).addMember(*xmProperty);
    return *xmProperty;
}



template
<
    class ClassT,
    typename RetT,
    typename ExtrParamT0,
    typename ExtrParamT1,
    typename ExtrParamT2
>
Property& bindProperty(
    const std::string& name,
    RetT (ClassT::*getter)
    ( 
        ExtrParamT0,
        ExtrParamT1,
        ExtrParamT2
    ) const,
    ExtrParamT0 extrArg0,
    ExtrParamT1 extrArg1,
    ExtrParamT2 extrArg2
)
{   
    // ensure that the type is registered
    registerType<RetT>();
    
    // remove constness from the getter method
    RetT (ClassT::*getter_nc)() =
        reinterpret_cast
        <
            RetT (ClassT::*)
            (
                ExtrParamT0,
                ExtrParamT1,
                ExtrParamT2
            )
        >(getter);
        
    // setter points to NULL
    void (ClassT::*setter)(Empty) =
        static_cast<void(ClassT::*)(Empty)>(NULL);
    
    // build the Property
    Property* xmProperty =
        new PropertyGetterNSetter_3_ExtrParams
        <
            ClassT,
            RetT,
            Empty,
            ExtrParamT0,
            ExtrParamT1,
            ExtrParamT2
        >
        (
            name,
            getter_nc,
            true,
            setter,
            extrArg0,
            extrArg1,
            extrArg2
        );
    const_cast<Class&>(getClass<ClassT>()).addMember(*xmProperty);
    return *xmProperty;
}



template
<
    class ClassT,
    typename RetT,
    typename ParamT,
    typename ExtrParamT0,
    typename ExtrParamT1,
    typename ExtrParamT2
>
Property& bindProperty(
    const std::string& name,
    RetT (ClassT::*getter)
    ( 
        ExtrParamT0,
        ExtrParamT1,
        ExtrParamT2
    ),
    void (ClassT::*setter)
    (
        ParamT,
        ExtrParamT0,
        ExtrParamT1,
        ExtrParamT2
    ),
    ExtrParamT0 extrArg0,
    ExtrParamT1 extrArg1,
    ExtrParamT2 extrArg2
)
{   
    // ensure that the type is registered
    registerType<RetT>();
    
    
    // build the Property
    Property* xmProperty =
        new PropertyGetterNSetter_3_ExtrParams
        <
            ClassT,
            RetT,
            ParamT,
            ExtrParamT0,
            ExtrParamT1,
            ExtrParamT2
        >
        (
            name,
            getter,
            false,
            setter,
            extrArg0,
            extrArg1,
            extrArg2
        );
    const_cast<Class&>(getClass<ClassT>()).addMember(*xmProperty);
    return *xmProperty;
}



template
<
    class ClassT,
    typename RetT,
    typename ParamT,
    typename ExtrParamT0,
    typename ExtrParamT1,
    typename ExtrParamT2
>
Property& bindProperty(
    const std::string& name,
    RetT (ClassT::*getter)
    ( 
        ExtrParamT0,
        ExtrParamT1,
        ExtrParamT2
    ) const,
    void (ClassT::*setter)
    (
        ParamT,
        ExtrParamT0,
        ExtrParamT1,
        ExtrParamT2
    ),
    ExtrParamT0 extrArg0,
    ExtrParamT1 extrArg1,
    ExtrParamT2 extrArg2
)
{   
    // ensure that the type is registered
    registerType<RetT>();
    
    // remove constness from the getter method
    RetT (ClassT::*getter_nc)() =
        reinterpret_cast
        <
            RetT (ClassT::*)
            (
                ExtrParamT0,
                ExtrParamT1,
                ExtrParamT2
            )
        >(getter);
        
    
    // build the Property
    Property* xmProperty =
        new PropertyGetterNSetter_3_ExtrParams
        <
            ClassT,
            RetT,
            ParamT,
            ExtrParamT0,
            ExtrParamT1,
            ExtrParamT2
        >
        (
            name,
            getter_nc,
            true,
            setter,
            extrArg0,
            extrArg1,
            extrArg2
        );
    const_cast<Class&>(getClass<ClassT>()).addMember(*xmProperty);
    return *xmProperty;
}



} // namespace xm

#endif	/* XM_BINDGETNSETPROPERTY_HPP */