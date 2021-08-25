#ifndef FLUTTER_PLUGIN_FIREBASE_AUTH_COMMON_H_
#define FLUTTER_PLUGIN_FIREBASE_AUTH_COMMON_H_

#include <flutter_linux/flutter_linux.h>
#include <map>
#include <vector>
#include <string>

#ifdef FLUTTER_PLUGIN_IMPL
#define FLUTTER_PLUGIN_EXPORT __attribute__((visibility("default")))
#else
#define FLUTTER_PLUGIN_EXPORT
#endif

// Constants

// Base
#define TAG "FLTFirebaseAuthPlugin"
#define ANDROID "android"
#define IOS "iOS"
#define MINIMUM_VERSION "minimumVersion"
#define INSTALL_APP "installApp"
#define PACKAGE_NAME "packageName"
#define BUNDLE_ID "bundleId"
#define APP_NAME "appName"

// Providers
#define SIGN_IN_METHOD_PASSWORD "password"
#define SIGN_IN_METHOD_EMAIL_LINK "emailLink"
#define SIGN_IN_METHOD_FACEBOOK "facebook.com"
#define SIGN_IN_METHOD_GOOGLE "google.com"
#define SIGN_IN_METHOD_TWITTER "twitter.com"
#define SIGN_IN_METHOD_GITHUB "github.com"
#define SIGN_IN_METHOD_PHONE "phone"
#define SIGN_IN_METHOD_OAUTH "oauth"

// User
#define USER "user"
#define EMAIL "email"
#define NEW_EMAIL "newEmail"
#define UID "uid"
#define USERNAME "username"
#define PASSWORD "password"
#define NEW_PASSWORD "newPassword"
#define PREVIOUS_EMAIL "previousEmail"
#define EMAIL_VERIFIED "emailVerified"
#define IS_ANONYMOUS "isAnonymous"
#define IS_NEW_USER "isNewUser"
#define METADATA "metadata"
#define DISPLAY_NAME "displayName"
#define PHONE_NUMBER "phoneNumber"
#define PHOTO_URL "photoURL"
#define PROFILE "profile"
#define ADDITIONAL_USER_INFO "additionalUserInfo"
#define CREATION_TIME "creationTime"
#define LAST_SIGN_IN_TIME "lastSignInTime"
#define TENANT_ID "tenantId"

// Auth
#define PROVIDERS "providers"
#define PROVIDER_ID "providerId"
#define PROVIDER_DATA "providerData"
#define AUTH_CREDENTIAL "authCredential"
#define CREDENTIAL "credential"
#define SECRET "secret"
#define REFRESH_TOKEN "refreshToken"
#define ID_TOKEN "idToken"
#define TOKEN "token"
#define ACCESS_TOKEN "accessToken"
#define CODE "code"
#define RAW_NONCE "rawNonce"
#define EMAIL_LINK "emailLink"
#define VERIFICATION_ID "verificationId"
#define SMS_CODE "smsCode"
#define URL "url"
#define DYNAMIC_LINK_DOMAIN "dynamicLinkDomain"
#define LANGUAGE_CODE "languageCode"
#define CLAIMS "claims"
#define TIMEOUT "timeout"
#define AUTH_TIMESTAMP "authTimestamp"
#define EXPIRATION_TIMESTAMP "expirationTimestamp"
#define ISSUED_AT_TIMESTAMP "issuedAtTimestamp"
#define SIGN_IN_METHOD "signInMethod"
#define SIGN_IN_PROVIDER "signInProvider"
#define SIGN_IN_SECOND_FACTOR "signInSecondFactor"
#define FORCE_RESENDING_TOKEN "forceResendingToken"
#define FORCE_REFRESH "forceRefresh"
#define TOKEN_ONLY "tokenOnly"
#define HANDLE_CODE_IN_APP "handleCodeInApp"
#define ACTION_CODE_SETTINGS "actionCodeSettings"
#define AUTO_RETRIEVED_SMS_CODE_FOR_TESTING "autoRetrievedSmsCodeForTesting"
#define HOST "host"
#define PORT "port"
#define NAME "name"
#define APP_VERIFICATION_DISABLED_FOR_TESTING
      "appVerificationDisabledForTesting"
#define FORCE_RECAPTCHA_FLOW "forceRecaptchaFlow"

#define FIREBASE_AUTH_METHOD_CHANNEL_NAME "plugins.flutter.io/firebase_auth"

#define FIREBASE_AUTH_REGISTER_ID_TOKEN_LISTENER "Auth#registerIdTokenListener"
#define FIREBASE_AUTH_REGISTER_AUTH_STATE_LISTENER "Auth#registerAuthStateListener"
#define FIREBASE_AUTH_APPLY_ACTION_CODE "Auth#applyActionCode"
#define FIREBASE_AUTH_CHECK_ACTION_CODE "Auth#checkActionCode"
#define FIREBASE_AUTH_CONFIRM_PASSWORD_RESET "Auth#confirmPasswordReset"
#define FIREBASE_AUTH_CREATE_USER_WITH_EMAIL_AND_PASSWORD "Auth#createUserWithEmailAndPassword"
#define FIREBASE_AUTH_FETCH_SIGN_IN_METHODS_FOR_EMAIL "Auth#fetchSignInMethodsForEmail"
#define FIREBASE_AUTH_SEND_PASSWORD_RESET_EMAIL "Auth#sendPasswordResetEmail"
#define FIREBASE_AUTH_SEND_SIGN_IN_LINK_TO_EMAIL "Auth#sendSignInLinkToEmail"
#define FIREBASE_AUTH_SIGN_IN_WITH_CREDENTIAL "Auth#signInWithCredential"
#define FIREBASE_AUTH_SET_LANGUAGE_CODE "Auth#setLanguageCode"
#define FIREBASE_AUTH_SET_SETTINGS "Auth#setSettings"
#define FIREBASE_AUTH_SIGN_IN_ANONYMOUSLY "Auth#signInAnonymously"
#define FIREBASE_AUTH_SIGN_IN_WITH_CUSTOM_TOKEN "Auth#signInWithCustomToken"
#define FIREBASE_AUTH_SIGN_IN_WITH_EMAIL_AND_PASSWORD "Auth#signInWithEmailAndPassword"
#define FIREBASE_AUTH_SIGN_IN_WITH_EMAIL_LINK "Auth#signInWithEmailLink"
#define FIREBASE_AUTH_SIGN_OUT "Auth#signOut"
#define FIREBASE_AUTH_USE_EMULATOR "Auth#useEmulator"
#define FIREBASE_AUTH_VERIFY_PASSWORD_RESET_CODE "Auth#verifyPasswordResetCode"
#define FIREBASE_AUTH_VERIFY_PHONE_NUMBER "Auth#verifyPhoneNumber"
#define FIREBASE_AUTH_USER_DELETE "User#delete"
#define FIREBASE_AUTH_USER_GET_ID_TOKEN "User#getIdToken"
#define FIREBASE_AUTH_USER_LINK_WITH_CREDENTIAL "User#linkWithCredential"
#define FIREBASE_AUTH_USER_REAUTHENTICATE_USER_WITH_CREDENTIAL "User#reauthenticateUserWithCredential"
#define FIREBASE_AUTH_RELOAD "User#reload"
#define FIREBASE_AUTH_SEND_EMAIL_VERIFICATION "User#sendEmailVerification"
#define FIREBASE_AUTH_UNLINK "User#unlink"
#define FIREBASE_AUTH_UPDATE_EMAIL "User#updateEmail"
#define FIREBASE_AUTH_UPDATE_PASSWORD "User#updatePassword"
#define FIREBASE_AUTH_UPDATE_PHONE_NUMBER "User#updatePhoneNumber"
#define FIREBASE_AUTH_UPDATE_PROFILE "User#updateProfile"
#define FIREBASE_AUTH_VERIFY_BEFORE_UPDATE_EMAIL "User#verifyBeforeUpdateEmail"

#endif  // FLUTTER_PLUGIN_FIREBASE_AUTH_COMMON_H_
