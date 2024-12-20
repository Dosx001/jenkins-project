pipeline {
  agent {
    docker {
      image 'localhost:5000/dev-test'
    }
  }
  stages {
    stage('Source') {
      steps {
        sh 'tar czvf $HOME/rpmbuild/SOURCES/jenkins-project.tar.gz .'
      }
    }
    stage('Build') {
      steps {
        sh 'rpmbuild -bb pkg/jenkins-project.spec'
      }
    }
  }
  post {
    always {
      archiveArtifacts artifacts: '$HOME/rpmbuild/RPMS/x86_64/*.rpm', fingerprint: true
    }
  }
}
