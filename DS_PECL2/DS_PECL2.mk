##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=DS_PECL2
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=C:/DS_PECL2
ProjectPath            :=C:/DS_PECL2/DS_PECL2
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/DS_PECL2
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=lublu
Date                   :=11/22/2023
CodeLitePath           :="C:/Program Files/CodeLite"
MakeDirCommand         :=mkdir
LinkerName             :=C:/msys64/clang64/bin/clang++.exe
SharedObjectLinkerName :=C:/msys64/clang64/bin/clang++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=C:/DS_PECL2/build-$(WorkspaceConfiguration)/bin
OutputFile             :=..\build-$(WorkspaceConfiguration)\bin\$(ProjectName).exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/msys64/clang64/bin/windres.exe
LinkOptions            :=  
IncludePath            := $(IncludeSwitch)C:\msys64\clang64\include\c++\v1 $(IncludeSwitch)C:\msys64\clang64\lib\clang\17\include $(IncludeSwitch)C:\msys64\clang64\include  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := C:/msys64/clang64/bin/ar.exe -r
CXX      := C:/msys64/clang64/bin/clang++.exe
CC       := C:/msys64/clang64/bin/clang.exe
CXXFLAGS :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
CFLAGS   :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/msys64/clang64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/sth.cpp$(ObjectSuffix) $(IntermediateDirectory)/Stack.cpp$(ObjectSuffix) $(IntermediateDirectory)/DLList.cpp$(ObjectSuffix) $(IntermediateDirectory)/BSTree.cpp$(ObjectSuffix) $(IntermediateDirectory)/Queue.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@if not exist "$(OutputDirectory)" $(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/DS_PECL2/DS_PECL2/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/sth.cpp$(ObjectSuffix): sth.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/DS_PECL2/DS_PECL2/sth.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sth.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sth.cpp$(PreprocessSuffix): sth.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sth.cpp$(PreprocessSuffix) sth.cpp

$(IntermediateDirectory)/Stack.cpp$(ObjectSuffix): Stack.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/DS_PECL2/DS_PECL2/Stack.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Stack.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Stack.cpp$(PreprocessSuffix): Stack.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Stack.cpp$(PreprocessSuffix) Stack.cpp

$(IntermediateDirectory)/DLList.cpp$(ObjectSuffix): DLList.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/DS_PECL2/DS_PECL2/DLList.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/DLList.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DLList.cpp$(PreprocessSuffix): DLList.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DLList.cpp$(PreprocessSuffix) DLList.cpp

$(IntermediateDirectory)/BSTree.cpp$(ObjectSuffix): BSTree.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/DS_PECL2/DS_PECL2/BSTree.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BSTree.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BSTree.cpp$(PreprocessSuffix): BSTree.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BSTree.cpp$(PreprocessSuffix) BSTree.cpp

$(IntermediateDirectory)/Queue.cpp$(ObjectSuffix): Queue.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/DS_PECL2/DS_PECL2/Queue.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Queue.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Queue.cpp$(PreprocessSuffix): Queue.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Queue.cpp$(PreprocessSuffix) Queue.cpp

##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


