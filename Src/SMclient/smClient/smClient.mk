##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=smClient
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Eros/gitHub/sharedMemoryClient/Src/SMclient
ProjectPath            :=C:/Users/Eros/gitHub/sharedMemoryClient/Src/SMclient/smClient
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Eros
Date                   :=22/03/2020
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
OutputFile             :=$(IntermediateDirectory)/$(ProjectName).dll
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="smClient.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
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
Objects0=$(IntermediateDirectory)/functions.c$(ObjectSuffix) $(IntermediateDirectory)/smClient.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(SharedObjectLinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)
	@$(MakeDirCommand) "C:\Users\Eros\gitHub\sharedMemoryClient\Src\SMclient/.build-debug"
	@echo rebuilt > "C:\Users\Eros\gitHub\sharedMemoryClient\Src\SMclient/.build-debug/smClient"

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/functions.c$(ObjectSuffix): functions.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/functions.c$(ObjectSuffix) -MF$(IntermediateDirectory)/functions.c$(DependSuffix) -MM functions.c
	$(CC) $(SourceSwitch) "C:/Users/Eros/gitHub/sharedMemoryClient/Src/SMclient/smClient/functions.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/functions.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/functions.c$(PreprocessSuffix): functions.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/functions.c$(PreprocessSuffix) functions.c

$(IntermediateDirectory)/smClient.c$(ObjectSuffix): smClient.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/smClient.c$(ObjectSuffix) -MF$(IntermediateDirectory)/smClient.c$(DependSuffix) -MM smClient.c
	$(CC) $(SourceSwitch) "C:/Users/Eros/gitHub/sharedMemoryClient/Src/SMclient/smClient/smClient.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/smClient.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/smClient.c$(PreprocessSuffix): smClient.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/smClient.c$(PreprocessSuffix) smClient.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


