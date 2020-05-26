#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <winapi-header-wrappers/windows-h.hpp>
#include <cppx-core-language/all.hpp>

namespace winapi::integration {
    $use_cppx( Size );

    class Abstract_image_displayer
    {
    public:
        virtual auto width() const  -> Size = 0;
        virtual auto height() const -> Size = 0;

        virtual void display_on( const HDC dc ) const = 0;
        virtual void stretch_display_on( const HDC dc, const RECT& rect ) const = 0;

        void stretch_display_on( const HDC dc, const POINT& size ) const
        {
            stretch_display_on( dc, RECT{ 0, 0, size.x, size.y } );
        }
    };

}  // namespace winapi
