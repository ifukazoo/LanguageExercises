# AWSを利用したTimeサーバ

## 準備

### AWS CLIのインストール

#### pipのインストール

``$ pip3 install awscli``

#### CLIの設定

``$ aws configure``

* アクセスキーなどは別途AWSのサイトから入手する.

## Lambda と API Gateway

* 最初にLambdaを作成して,トリガーとしてAPI Gatewayを作成するとスムーズ