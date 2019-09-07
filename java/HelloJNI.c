// Save as "HelloJNI.c"
#include <jni.h>        // JNI header provided by JDK
#include <string.h>
#include <stdlib.h>
#include <stdio.h>      // C Standard IO Header
#include "HelloJNI.h"   // Generated
#include <sys/types.h>
#include <unistd.h>

// Implementation of the native method sayHello()
JNIEXPORT void
JNICALL
Java_HelloJNI_sayHello (JNIEnv *env, jobject thisObj)
{
  printf ("Hello World!\n");
  return;
}

JNIEXPORT jstring
JNICALL
Java_HelloJNI_addOne (JNIEnv *env, jobject thisObj, jint y)
{
  int a = 1;
  char *msg = NULL;
  msg = (char *) malloc (sizeof (char) * 40);
  sprintf (msg, "%d", a + y);

  // return env->NewStringUTF (msg);
  return (*env)->NewStringUTF (env, msg);
}

JNIEXPORT void
JNICALL
Java_HelloJNI_fork (JNIEnv *env, jobject thisObj)
{
  printf ("Fork time!");

  if (fork() == 0)
    {
      printf ("I am the child...what will I do??\n");

      return;
    }

  printf ("And I am not the child, I am the parent!\n");

  return;
}
