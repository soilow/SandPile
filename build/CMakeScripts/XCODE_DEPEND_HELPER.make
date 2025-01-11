# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.image.Debug:
/Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/image/Debug/libimage.a:
	/bin/rm -f /Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/image/Debug/libimage.a


PostBuild.main.Debug:
PostBuild.model.Debug: /Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/Debug/main
PostBuild.image.Debug: /Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/Debug/main
/Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/Debug/main:\
	/Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/model/Debug/libmodel.a\
	/Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/image/Debug/libimage.a
	/bin/rm -f /Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/Debug/main


PostBuild.model.Debug:
/Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/model/Debug/libmodel.a:
	/bin/rm -f /Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/model/Debug/libmodel.a


PostBuild.image.Release:
/Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/image/Release/libimage.a:
	/bin/rm -f /Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/image/Release/libimage.a


PostBuild.main.Release:
PostBuild.model.Release: /Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/Release/main
PostBuild.image.Release: /Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/Release/main
/Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/Release/main:\
	/Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/model/Release/libmodel.a\
	/Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/image/Release/libimage.a
	/bin/rm -f /Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/Release/main


PostBuild.model.Release:
/Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/model/Release/libmodel.a:
	/bin/rm -f /Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/model/Release/libmodel.a


PostBuild.image.MinSizeRel:
/Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/image/MinSizeRel/libimage.a:
	/bin/rm -f /Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/image/MinSizeRel/libimage.a


PostBuild.main.MinSizeRel:
PostBuild.model.MinSizeRel: /Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/MinSizeRel/main
PostBuild.image.MinSizeRel: /Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/MinSizeRel/main
/Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/MinSizeRel/main:\
	/Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/model/MinSizeRel/libmodel.a\
	/Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/image/MinSizeRel/libimage.a
	/bin/rm -f /Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/MinSizeRel/main


PostBuild.model.MinSizeRel:
/Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/model/MinSizeRel/libmodel.a:
	/bin/rm -f /Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/model/MinSizeRel/libmodel.a


PostBuild.image.RelWithDebInfo:
/Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/image/RelWithDebInfo/libimage.a:
	/bin/rm -f /Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/image/RelWithDebInfo/libimage.a


PostBuild.main.RelWithDebInfo:
PostBuild.model.RelWithDebInfo: /Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/RelWithDebInfo/main
PostBuild.image.RelWithDebInfo: /Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/RelWithDebInfo/main
/Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/RelWithDebInfo/main:\
	/Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/model/RelWithDebInfo/libmodel.a\
	/Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/image/RelWithDebInfo/libimage.a
	/bin/rm -f /Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/RelWithDebInfo/main


PostBuild.model.RelWithDebInfo:
/Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/model/RelWithDebInfo/libmodel.a:
	/bin/rm -f /Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/model/RelWithDebInfo/libmodel.a




# For each target create a dummy ruleso the target does not have to exist
/Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/image/Debug/libimage.a:
/Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/image/MinSizeRel/libimage.a:
/Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/image/RelWithDebInfo/libimage.a:
/Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/image/Release/libimage.a:
/Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/model/Debug/libmodel.a:
/Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/model/MinSizeRel/libmodel.a:
/Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/model/RelWithDebInfo/libmodel.a:
/Users/deus/Projects/С++/Programming_Basics/Laba3/Laba3_reincarnation/public/yzhe_tochno/labwork3-soilow/build/model/Release/libmodel.a:
