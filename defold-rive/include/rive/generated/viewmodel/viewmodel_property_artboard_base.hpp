#ifndef _RIVE_VIEW_MODEL_PROPERTY_ARTBOARD_BASE_HPP_
#define _RIVE_VIEW_MODEL_PROPERTY_ARTBOARD_BASE_HPP_
#include "rive/viewmodel/viewmodel_property.hpp"
namespace rive
{
class ViewModelPropertyArtboardBase : public ViewModelProperty
{
protected:
    typedef ViewModelProperty Super;

public:
    static const uint16_t typeKey = 598;

    /// Helper to quickly determine if a core object extends another without
    /// RTTI at runtime.
    bool isTypeOf(uint16_t typeKey) const override
    {
        switch (typeKey)
        {
            case ViewModelPropertyArtboardBase::typeKey:
            case ViewModelPropertyBase::typeKey:
            case ViewModelComponentBase::typeKey:
                return true;
            default:
                return false;
        }
    }

    uint16_t coreType() const override { return typeKey; }

    Core* clone() const override;

protected:
};
} // namespace rive

#endif