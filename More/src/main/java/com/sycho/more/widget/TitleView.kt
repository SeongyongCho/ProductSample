package com.sycho.more.widget

import android.content.Context
import android.util.AttributeSet
import android.view.LayoutInflater
import android.widget.RelativeLayout
import android.widget.TextView
import com.sycho.more.R
import kotlinx.android.synthetic.main.widget_title_view.view.*

/**
 * Description
 *
 * @author Cho Seong-yong
 * @since 2019.04.30
 */
class TitleView : RelativeLayout {

    private var title: String? = null

    private val titleView: TextView

    constructor(context: Context?) : this(context, null)
    constructor(context: Context?, attrs: AttributeSet?) : this(context, attrs, 0)
    constructor(context: Context?, attrs: AttributeSet?, defStyleAttr: Int) : this(
        context,
        attrs,
        defStyleAttr,
        0
    )

    constructor(
        context: Context?,
        attrs: AttributeSet?,
        defStyleAttr: Int,
        defStyleRes: Int
    ) : super(context, attrs, defStyleAttr, defStyleRes) {
        val layoutInflater = LayoutInflater.from(context)
        layoutInflater.inflate(R.layout.widget_title_view, this)

        titleView = title_text_view

        attrs?.let {
            val a = context?.obtainStyledAttributes(it, R.styleable.TitleView)
            title = a?.getString(R.styleable.TitleView_titleText)
            a?.recycle()
        }

        setTitleView()
    }

    private fun setTitleView() {
        title?.let {
            titleView.text = title
        }
    }

    fun setTitle(title: String) {
        this.title = title
        setTitleView()
    }
}