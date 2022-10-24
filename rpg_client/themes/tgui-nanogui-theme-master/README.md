# TGUI Theme Builder

License: zlib

## Use in Continuous Integration

This code will download this tools source code, and build a given theme's source code

```bash
git clone https://gitlab.com/rubenwardy/tgui-theme-builder
tgui-theme-builder/build.sh nanogui.style
mv build/theme.zip theme.zip
```

Here's an example `.gitlab-ci.yml`:

```yml
image: python:3.7

before_script:
  - apt-get update
  - apt-get install zip

build:
  stage: build
  script:
    - git clone https://gitlab.com/rubenwardy/tgui-theme-builder
    - tgui-theme-builder/build.sh nanogui.style
    - mv build/theme.zip theme.zip
  artifacts:
    paths:
    - theme.zip
  only:
    - master
```

## Use in CMake

```cmake
file(GLOB GUISources ${CMAKE_SOURCE_DIR}/assets/gui/source/*)
add_custom_target(prebuild ALL
	COMMAND utils/prebuild.sh
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
	DEPENDS ${GUISources}
	BYPRODUCTS ${CMAKE_SOURCE_DIR}/assets/gui/rvwp.style ${CMAKE_SOURCE_DIR}/assets/gui/rvwp.png)
```

where `prebuild.sh` is found in this repo.
