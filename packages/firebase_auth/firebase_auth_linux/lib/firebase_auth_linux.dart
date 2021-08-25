
import 'dart:async';

import 'package:flutter/services.dart';

class FirebaseAuthLinux {
  static const MethodChannel _channel = MethodChannel('firebase_auth_linux');

  static Future<String?> get platformVersion async {
    final String? version = await _channel.invokeMethod('getPlatformVersion');
    return version;
  }
}
