#pragma once

enum Numbers { ONE = 1, TWO, THREE };

const char *NumbersToString(int n) {
  switch (n) {
  case ONE: {
    return "one";
  }
  case TWO: {
    return "two";
  }
  case THREE: {
    return "three";
  }
  default:
    return "unknown";
  }
}