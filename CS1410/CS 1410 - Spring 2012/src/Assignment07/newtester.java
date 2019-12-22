package Assignment07;

import java.io.File;

public class newtester
{

    private static void printList (String note, File[] files)
    {
        if (files.length == 0)
        {
            System.out.println(note + ":   []");
            return;
        }
        System.out.print(note + ":   [" + files[0]);
        for (int i = 1; i < files.length; ++i)
        {
            System.out.print(", " + files[i]);
        }
        System.out.println("]");
    }

    private static boolean assertArrayEquals (File[] output, File[] expected, File[] original)
    {
        boolean testOK = true;
        if (output.length != expected.length)
        {
            testOK = false;
        }
        else
        {
            File[] copy = new File[output.length];
            for (int i = 0; i < output.length; ++i)
                copy[i] = output[i];

            for (int i = 0; i < expected.length; ++i)
            {
                boolean foundIt = false;
                for (int j = 0; j < copy.length; ++j)
                {
                    if (expected[i].equals(copy[j]))
                    {
                        copy[j] = null;
                        foundIt = true;
                    }
                }
                if (!foundIt)
                {
                    testOK = false;
                    break;
                }
            }
        }
        if (!testOK)
        {
            System.out.println("Test failed");
            printList("Given", original);
            printList("Expected", expected);
            printList("Actual", output);
            System.out.println();
        }
        return testOK;
    }

    public static void main (String[] args)
    {
        File a = new File("alpha");
        File b = new File("beta");
        File c = new File("charlie");
        File d = new File("delta");
        File e = new File("epsilon");
        File f = new File("foxtrot");
        File g = new File("golf");
        File h = new File("hotel");
        File i = new File("india");
        File j = new File("juliet");
        File k = new File("kilo");
        File l = new File("lima");

        File ecopy = new File("epsilon");

        File[] unique = null;

        int testsPassed = 0;

        try
        {
            File[] test1 = new File[] { a, a, b, b, c, c };
            unique = ArrayExercises.getUnique(test1);
            if (assertArrayEquals(unique, new File[] { a, b, c }, test1))
                testsPassed++;
        }
        catch (Throwable x)
        {
            System.out.println("Test 1: Error:    " + x);
            System.out.println("Test 1 input contains multiples of all files");
            System.out.println();
        }

        try
        {
            File[] test2 = new File[] { h, a, g, a, l };
            unique = ArrayExercises.getUnique(test2);
            if (assertArrayEquals(unique, new File[] { a, g, h, l }, test2))
                testsPassed++;
        }
        catch (Throwable x)
        {
            System.out.println("Test 2: Error:    " + x);
            System.out.println("Test 2 input contains multiples of one file and many unique files");
            System.out.println();
        }

        try
        {
            File[] test3 = new File[] { a };
            unique = ArrayExercises.getUnique(test3);
            if (assertArrayEquals(unique, new File[] { a }, test3))
                testsPassed++;
        }
        catch (Throwable x)
        {
            System.out.println("Test 3: Error:    " + x);
            System.out.println("Test 3 input contains a single file");
            System.out.println();
        }

        try
        {
            File[] test4 = new File[] { f, f, f, f, f, f, f };
            unique = ArrayExercises.getUnique(test4);
            if (assertArrayEquals(unique, new File[] { f }, test4))
                testsPassed++;
        }
        catch (Throwable x)
        {
            System.out.println("Test 4: Error:    " + x);
            System.out.println("Test 4 input contains many multiples of a single file");
            System.out.println();
        }

        try
        {
            File[] test5 = new File[] { a, b, c, d, e };
            unique = ArrayExercises.getUnique(test5);
            if (assertArrayEquals(unique, new File[] { a, b, c, d, e }, test5))
                testsPassed++;
        }
        catch (Throwable x)
        {
            System.out.println("Test 5: Error:    " + x);
            System.out.println("Test 5 input contains all unique files");
            System.out.println();
        }

        try
        {
            File[] test6 = new File[] { null, null, null };
            unique = ArrayExercises.getUnique(test6);
            System.out.println("Test 6 should have thrown NullPointerException!\n");
            System.out.println("Test 6 contains null filesas input");
        }
        catch (NullPointerException x)
        {
            testsPassed++;
        }
        catch (Throwable x)
        {
            System.out.println("Error:    " + x);
            System.out.println();
        }

        try
        {
            File[] test7 = new File[] { l, k, j, i, h, g };
            unique = ArrayExercises.getUnique(test7);
            if (assertArrayEquals(unique, new File[] { g, h, i, j, k, l }, test7))
                testsPassed++;
        }
        catch (Throwable x)
        {
            System.out.println("Test 7: Error:    " + x);
            System.out.println("Test 7 contains all unique files but your program threw an error");
            System.out.println();
        }

        try
        {
            File[] test8 = new File[] { a, a, a, a, a, a, j, a, a, a, a, a, a };
            unique = ArrayExercises.getUnique(test8);
            if (assertArrayEquals(unique, new File[] { a, j }, test8))
                testsPassed++;
        }
        catch (Throwable x)
        {
            System.out.println("Test 8: Error:    " + x);
            System.out
                    .println("Test 8 input contains multiples of one file plus one unique file,\n but your program threw an error");
            System.out.println();
        }

        try
        {
            File[] test9 = new File[] { e, ecopy };
            unique = ArrayExercises.getUnique(test9);
            if (assertArrayEquals(unique, new File[] { e }, test9))
                testsPassed++;
        }
        catch (Throwable x)
        {
            System.out.println("Test 9: Error:    " + x);
            System.out.println("Test 9 input contains a single file, but your program threw an error");
            System.out.println();
        }

        try
        {
            File[] test10 = new File[] {};
            unique = ArrayExercises.getUnique(test10);
            if (assertArrayEquals(unique, new File[] {}, test10))
                testsPassed++;
        }
        catch (Throwable x)
        {
            System.out.println("Test 10: Error:    " + x);
            System.out
                    .println("Test 10 input is empty, there are no unique files.\n This should not throw an error it should just return an empty list.\n Your program however threw an error");
            System.out.println();
        }

        System.out.println("Unique Tests Passed: " + testsPassed + "/10\n");
    }

}
