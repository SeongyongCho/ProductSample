package com.sycho.logic

/**
 * Description
 *
 * @author Cho Seong-yong
 * @since 2019.04.30
 */
class Logic {

    companion object {
        init {
            System.loadLibrary("native_logic")
        }
    }

    external fun createCppObject()

    external fun setValues(a: Int, b: Int)

    external fun add(): Int

    external fun deleteCppObject()

}