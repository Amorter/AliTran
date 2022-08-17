# 翻译器
基于QT框架，阿里云OSS和OPENAPI的翻译器

#1使用条件：
1.开通阿里云账户
2.开通OSS对象储存和文档翻译服务
3.windows64位

#2使用方法
1.第一次启动默认英文，在左上角menu->language->zh改成中文(需重启应用)
2.menu->api option设置阿里云账户的AccessKeyID和AccessKeySecret(OSS和文档翻译默认使用同一个AccessKey，暂时没有设置分离，开通服务请使用同一账户)
3.点击save，保存api option
4.在主界面文本框粘贴想要翻译的内容，单击翻译按钮(暂仅支持英译中)
5.output.txt自动导出到根目录
