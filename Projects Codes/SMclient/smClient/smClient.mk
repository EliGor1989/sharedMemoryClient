##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=smClient
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=C:/Users/Eros/gitProjects/sharedmemory/SMclient
ProjectPath            :=C:/Users/Eros/gitProjects/sharedmemory/SMclient/smClient
IntermediateDirectory  :=../build-$(ConfigurationName)/smClient
OutDir                 :=../build-$(ConfigurationName)/smClient
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Eros
Date                   :=30/01/2020
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-32/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-32/bin/g++.exe -shared -fPIC
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
RcCompilerName         :=C:/TDM-GCC-32/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-32/bin/ar.exe rcu
CXX      := C:/TDM-GCC-32/bin/g++.exe
CC       := C:/TDM-GCC-32/bin/gcc.exe
CXXFLAGS :=  -g  $(Preprocessors)
CFLAGS   :=  -g  $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-32/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=../build-$(ConfigurationName)/smClient/functions.c$(ObjectSuffix) ../build-$(ConfigurationName)/smClient/smClient.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/smClient/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\smClient" mkdir "..\build-$(ConfigurationName)\smClient"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(SharedObjectLinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)
	@echo rebuilt > $(IntermediateDirectory)/smClient.relink

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\smClient" mkdir "..\build-$(ConfigurationName)\smClient"
	@if not exist ""..\build-$(ConfigurationName)\lib"" mkdir ""..\build-$(ConfigurationName)\lib""

../build-$(ConfigurationName)/smClient/.d:
	@if not exist "..\build-$(ConfigurationName)\smClient" mkdir "..\build-$(ConfigurationName)\smClient"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/smClient/functions.c$(ObjectSuffix): functions.c ../build-$(ConfigurationName)/smClient/functions.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Eros/gitProjects/sharedmemory/SMclient/smClient/functions.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/functions.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/smClient/functions.c$(DependSuffix): functions.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/smClient/functions.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/smClient/functions.c$(DependSuffix) -MM functions.c

../build-$(ConfigurationName)/smClient/functions.c$(PreprocessSuffix): functions.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/smClient/functions.c$(PreprocessSuffix) functions.c

../build-$(ConfigurationName)/smClient/smClient.c$(ObjectSuffix): smClient.c ../build-$(ConfigurationName)/smClient/smClient.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Eros/gitProjects/sharedmemory/SMclient/smClient/smClient.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/smClient.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/smClient/smClient.c$(DependSuffix): smClient.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/smClient/smClient.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/smClient/smClient.c$(DependSuffix) -MM smClient.c

../build-$(ConfigurationName)/smClient/smClient.c$(PreprocessSuffix): smClient.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/smClient/smClient.c$(PreprocessSuffix) smClient.c


-include ../build-$(ConfigurationName)/smClient//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


