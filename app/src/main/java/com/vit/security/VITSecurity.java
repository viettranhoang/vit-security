package com.vit.security;

import android.content.Context;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.Signature;

/**
 * @author vit
 */
public class VITSecurity {

    public static native String adMobInterstitialRandomId();

    public static native String adMobInterstitialNormalId();

    public static native String adMobBannerId();

    public static native String settingUrl();

    public static native String encode(Object context, String str);

    public static native String decode(Object context, String str);

    public static native boolean checkSignature(Object context);

    public static boolean isDebug() {
        return BuildConfig.DEBUG;
    }

    public static int getSignature(Context context) {
        try {
            String packageName = context.getPackageName();
            PackageInfo packageInfo =
                    context.
                            getPackageManager().
                            getPackageInfo(packageName, PackageManager.GET_SIGNATURES);

            Signature[] signs = packageInfo.signatures;
            Signature sign = signs[0];
            return sign.hashCode();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return -1;
    }


    static {
        System.loadLibrary("native-encrypt");
    }
}
