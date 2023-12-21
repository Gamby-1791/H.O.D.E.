/**
 * Standalone program to list out io-warriors plugged into USB
 * - does not work, use driver/iow56list.`uname -m`
 *
 *  make
 *  run as root:
 *    ./runjava.sh IOW56List
 */

import com.codemercs.iow.IowKit;

public class IOW56List {
    public static void main (String[] args)
    {
        IowKit.openDevice ();
        long ndevs = IowKit.getNumDevs ();
        System.out.println ("ndevs=" + ndevs);
        for (int i = 0; ++ i <= ndevs;) {
            long iowhandle = IowKit.getDeviceHandle (i);
            String iowserial = IowKit.getSerialNumber (iowhandle);
            System.out.println (i + " " + iowserial);
        }
    }
}
