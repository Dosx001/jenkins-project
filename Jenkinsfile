pipeline {
  agent {
    docker {
      image 'localhost:5000/dev-test'
    }
  }
  stages {
    stage('Style') {
      steps {
        sh 'find src -type f -exec clang-format -in -Werror {} +'
      }
    }
    stage('Lint') {
      steps {
        sh 'cppcheck --enable=warning,style,performance,portability,unusedFunction --template=gcc --error-exitcode=1 src'
      }
    }
    stage('Build') {
      steps {
        sh 'cmake CMakeLists.txt; make'
      }
    }
    stage('Test') {
      steps {
        echo 'make tests'
      }
    }
  }
}
