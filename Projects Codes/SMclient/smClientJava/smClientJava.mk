##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=smClientJava
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=C:/Users/Eros/gitProjects/sharedmemory/SMclient
ProjectPath            :=C:/Users/Eros/gitProjects/sharedmemory/SMclient/smClientJava
IntermediateDirectory  :=../build-$(ConfigurationName)/smClientJava
OutDir                 :=../build-$(ConfigurationName)/smClientJava
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Eros
Date                   :=30/01/2020
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=..\build-$(ConfigurationName)\lib\$(ProjectName).dll
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)"C:\Program Files\Java\jdk-12.0.2\include" $(IncludeSwitch)"C:\Program Files\Java\jdk-12.0.2\include\win32" 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=../build-$(ConfigurationName)/smClientJava/SmClient.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/smClientJava/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\smClientJava" mkdir "..\build-$(ConfigurationName)\smClientJava"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(SharedObjectLinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)
	@echo rebuilt > $(IntermediateDirectory)/smClientJava.relink

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\smClientJava" mkdir "..\build-$(ConfigurationName)\smClientJava"
	@if not exist ""..\build-$(ConfigurationName)\lib"" mkdir ""..\build-$(ConfigurationName)\lib""

../build-$(ConfigurationName)/smClientJava/.d:
	@if not exist "..\build-$(ConfigurationName)\smClientJava" mkdir "..\build-$(ConfigurationName)\smClientJava"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/smClientJava/SmClient.cpp$(ObjectSuffix): SmClient.cpp ../build-$(ConfigurationName)/smClientJava/SmClient.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Eros/gitProjects/sharedmemory/SMclient/smClientJava/SmClient.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SmClient.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/smClientJava/SmClient.cpp$(DependSuffix): SmClient.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/smClientJava/SmClient.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/smClientJava/SmClient.cpp$(DependSuffix) -MM SmClient.cpp

../build-$(ConfigurationName)/smClientJava/SmClient.cpp$(PreprocessSuffix): SmClient.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/smClientJava/SmClient.cpp$(PreprocessSuffix) SmClient.cpp


-include ../build-$(ConfigurationName)/smClientJava//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


