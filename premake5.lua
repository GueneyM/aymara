workspace "aymara"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "aymara"
	location "aymara"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

files 
{
	"%{prj.name}/src/**.h",
	"%{prj.name}/src/**.cpp"
}

includedirs
{
	"%{prj.name}/vendor/spdlog/include"
}

filter "system:windows"
	cppdialect "C++17"
	staticruntime "On"
	systemversion "latest"

	defines
	{
		AYM_PLATFORM_WINDOWS, 
		AYM_BUILD_DLL,
	}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}

	filter "configurations:Debug"
		defines "AYM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AYM_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "AYM_DIST"
		symbols "On"



project "Sandbox"
	location "aymara"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

files 
{
	"%{prj.name}/src/**.h",
	"%{prj.name}/src/**.cpp"
}

includedirs
{
	"%{prj.name}/vendor/spdlog/include",
	"aymara/src"
}

links
{
	"aymara"
}

filter "system:windows"
	cppdialect "C++17"
	staticruntime "On"
	systemversion "latest"

	defines
	{
		AYM_PLATFORM_WINDOWS, 
	}

filter "configurations:Debug"
	defines "AYM_DEBUG"
	symbols "On"

filter "configurations:Release"
	defines "AYM_RELEASE"
	symbols "On"

filter "configurations:Dist"
	defines "AYM_DIST"
	symbols "On"


